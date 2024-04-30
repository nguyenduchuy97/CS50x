-- Keep a log of any SQL queries you execute as you solve the mystery.

-- First looking for a crime scene report that matches the date and the location of the crime.
SELECT * FROM crime_scene_reports WHERE month = 7 AND day = 28;

-- See the interview with three transcripts of witnesses.
SELECT * FROM interviews WHERE year = 2023 AND month = 7 AND day = 28;

-- See Bekery security logs as Ruth have said.
SELECT * FROM people WHERE license_plate =
(SELECT license_plate FROM bakery_security_logs
WHERE month = 7 AND day = 28 AND hour = 10 AND minute > 15
AND minute < 25 AND activity = "exit");

-- See the ATM transaction on Leggett Street
SELECT * FROM people WHERE id =
(SELECT person_id FROM bank_accounts WHERE account_number =
(SELECT account_number FROM atm_transactions WHERE year = 2023
AND month = 7 AND day = 28 AND atm_location = "Leggett Street"
AND transaction_type = "withdraw"));

-- See the phone calls logs
SELECT * FROM people WHERE phone_number =
(SELECT caller FROM phone_calls WHERE year = 2023
AND month = 7 AND day = 28 AND duration < 60);

-- Based on the results I conclude that the theif actually in the phone call.
-- So I seek for the receiver of the phone call.
SELECT * FROM people WHERE phone_number =
(SELECT reciever FROM phone_calls WHERE caller = "(130) 555-0289"
AND year = 2023 AND month = 7 AND day = 28 AND duration < 60);

