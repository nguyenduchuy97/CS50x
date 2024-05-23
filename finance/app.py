import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_data = db.execute(
        "SELECT username, cash FROM users WHERE id = ?",
        session["user_id"]
        )

    user = user_data[0]["username"]
    cash = user_data[0]["cash"]

    portfolio = db.execute("""
        SELECT symbol, SUM(CASE WHEN type = 'buy' THEN shares ELSE -shares END)
        AS total_shares
        FROM (
            SELECT symbol, shares, 'buy' AS type FROM buys WHERE user = ?
            UNION ALL
            SELECT symbol, shares, 'sell' AS type FROM sells WHERE user = ?
        )
        GROUP BY symbol
        HAVING total_shares > 0
    """, user, user)

    current = []
    total = cash
    total_stock_price = 0
    for stock in portfolio:
        symbol = stock["symbol"]
        total_shares = stock["total_shares"]

        if total_shares is None:
            continue

        info = lookup(symbol)
        if info is None:
            continue
        price = info["price"]

        total_stock_price = price * total_shares

        current.append({
            "symbol": symbol,
            "price": price,
            "shares": total_shares,
            "total": total_stock_price
        })

        total += total_stock_price

    return render_template(
        "index.html",
         current=current,
         cash=cash,
         total_stock_price=total_stock_price,
         total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # GET request
    if request.method == "GET":
        return render_template("buy.html")
    # POST request
    else:
        input = request.form.get("symbol")
        shares = int(request.form.get("shares"))

        if not input:
            return apology("Please input a stock’s symbol.", 403)

        if not shares or shares < 0:
            return apology("The shares must be positive number", 403)

        output = lookup(input)
        if not output:
            return apology("Symbol does not exist.", 403)

        price = output["price"]
        cash_result = db.execute(
            "SELECT cash FROM users WHERE id = ?",
            session["user_id"]
            )
        cash = cash_result[0]["cash"]

        user_result = db.execute(
            "SELECT username FROM users WHERE id = ?",
            session["user_id"]
            )
        user = user_result[0]["username"]
        total_costs = shares * price

        if total_costs > cash:
            return apology("Your cash under the price", 403)
        else:
            new_balance = cash - total_costs
            db.execute(
            "INSERT INTO buys (symbol, user, shares, price, dates) VALUES(?, ?, ?, ?, datetime('now'))",
              input, user, shares, price
            )

            db.execute(
                "UPDATE users SET cash = ? WHERE id = ?",
            new_balance, session["user_id"]
            )

        return redirect("/")



@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_result = db.execute(
            "SELECT username FROM users WHERE id = ?",
            session["user_id"]
            )
    user = user_result[0]["username"]
    bought = db.execute("SELECT * FROM buys WHERE user = ?", user)
    sold = db.execute("SELECT * FROM sells WHERE user = ?", user)
    return render_template("history.html", bought=bought, sold=sold)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?",
            request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    # Handle GET requests
    if request.method == "GET":
        return render_template("quote.html")
    # Handle GET requests
    else:
        symbol = request.form.get("symbol")
        # Handle input
        if not symbol:
            return apology("Please enter a stock symbol", 200)

        symbols = lookup(symbol)
        # Handle input
        if not symbols or not symbols["symbol"]:
            return apology("Symbol does not exist!", 403)

        return render_template("quoted.html", symbols=symbols)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    #clear session
    session.clear()

    #
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        if not request.form.get("password"):
            return apology("must provide password", 403)

        # Ensure confimation was submitted
        if not request.form.get("confirmation"):
            return apology("must confirm the password", 403)

        username = request.form.get("username")
        password = request.form.get("password")
        confirm = request.form.get("confirmation")

        # Query database for username
        user_exist = db.execute(
            "SELECT * FROM users WHERE username = ?", username
            )

        # Ensure username does not exist
        if user_exist:
            return apology("username already existed", 403)

        # Ensure password and confirmation matched
        if password != confirm:
            return apology("Passwords do not matched", 403)

        hash_password = generate_password_hash(password)

        db.execute(
            "INSERT INTO users (username, hash) VALUES(?, ?)",
            username, hash_password)

        flash("Registered successfully! Please login.")

        return redirect("/login")

    # User reached route via GET ( as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    user_result = db.execute("SELECT username, cash FROM users WHERE id = ?",
                             session["user_id"])
    user = user_result[0]["username"]
    cash = user_result[0]["cash"]
    portfolio = db.execute("""
        SELECT symbol, SUM(CASE WHEN type = 'buy' THEN shares ELSE -shares END)
        AS total_shares
        FROM (
            SELECT symbol, shares, 'buy' AS type FROM buys WHERE user = ?
            UNION ALL
            SELECT symbol, shares, 'sell' AS type FROM sells WHERE user = ?
        )
        GROUP BY symbol
        HAVING total_shares > 0
    """, user, user)

    if request.method == "GET":
        return render_template("sell.html", portfolio=portfolio)
    else:
        symbol = request.form.get("symbol")
        input = int(request.form.get("shares"))
        # Handle inputs
        if not symbol:
            return apology("Please enter the symbol to sell.", 403)
        if not input or input < 0:
            return apology("Please enter the number of shares to sell.", 403)
        shares = 0
        for stock in portfolio:
            if stock["symbol"] == symbol:
                shares = stock["total_shares"]

        if shares == 0:
            return apology("You don't have any shares of this stock.", 403)

        prices = lookup(symbol)
        if not prices:
            return apology("Symbol does not exist.", 403)
        price = prices["price"]

        db.execute(
            "INSERT INTO sells (symbol, user, shares, price, dates) VALUES(?, ?, ?, ?, datetime('now'))", symbol,
            user, shares, price
            )
        total_price = price * shares
        new_balance = cash + total_price
        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_balance, session["user_id"])

        return redirect("/")

@app.route("/reset", methods=["GET", "POST"])
@login_required
def reset():
    """Reset password"""

    if request.method == "GET":
        return render_template("reset.html")
    else:
        pass
