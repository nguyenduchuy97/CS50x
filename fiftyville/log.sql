-- Keep a log of any SQL queries you execute as you solve the mystery.

-- First looking for a crime scene report that matches the date and the location of the crime.
SELECT * FROM crime_scene_reports WHERE month = 7 AND day = 28;

-- See the interview with three transcripts of witnesses.
SELECT * FROM interviews WHERE year = 2023 AND month = 7 AND day = 28;


-- Select Bekery security logs as Ruth have said.
SELECT * FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE month = 7
AND day = 28 AND hour = 10 AND minute > 5 AND minute < 25 AND activity = "exit")
-- Select the ATM transaction on Leggett Street
AND id IN (SELECT person_id FROM bank_accounts WHERE account_number
IN (SELECT account_number FROM atm_transactions WHERE year = 2023
AND month = 7 AND day = 28 AND atm_location = "Leggett Street"
AND transaction_type = "withdraw"))
-- Select the phone calls logs
AND phone_number IN
(SELECT caller FROM phone_calls WHERE year = 2023
AND month = 7 AND day = 28 AND duration < 60)
-- Select the earliest flight on the next day of the theft.
AND passport_number
IN (SELECT passport_number FROM passengers WHERE flight_id
IN (SELECT id FROM flights WHERE year = 2023 AND month = 7
AND day = 29 ORDER BY hour, minute LIMIT 1));

-- Find the ACCOMPLICE based on the thief was found.
SELECT * FROM people WHERE phone_number
IN (SELECT receiver FROM phone_calls WHERE caller = "(367) 555-5533"
AND year = 2023 AND month = 7 AND day = 28 AND duration < 60);
