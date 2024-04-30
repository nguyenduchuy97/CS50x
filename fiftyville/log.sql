-- Keep a log of any SQL queries you execute as you solve the mystery.

-- First looking for a crime scene report that matches the date and the location of the crime.
SELECT * FROM crime_scene_reports WHERE month = 7 AND day = 28;

-- See the interview with three transcripts of witnesses.
SELECT * FROM interviews WHERE year = 2023 AND month = 7 AND day = 28;

-- See 
