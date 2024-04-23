SELECT name
FROM people
JOIN stars
ON people.id = stars.person_id
JOIN movies
ON movies.id = movie_id
WHERE stars.person_id = people.id
AND movies.year = "2004"
ORDER BY people.birth;
