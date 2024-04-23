SELECT name
FROM people
JOIN stars
ON people.id = stars.person_id
JOIN movies
ON movies.id = stars.movie_id
JOIN ratings
ON ratings.movie_id = movies.id
WHERE ratings.rating = movies.id
AND people.name
