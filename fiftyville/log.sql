-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find the ID of the airport where the original place of the theft.
SELECT id, abbreviation, full_name, city FROM airports;

-- Find the origin airport
SELECT * FROM flights WHERE origin_airport_id = 8 AND day = 28;
