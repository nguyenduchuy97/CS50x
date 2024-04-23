SELECT title, rating
FROM movies
JOIN ratings
ON movies.id = ratings.movie_id
WHERE movies.year = "2010"
EXCEPT ratings.rating = 0
ORDER BY ratings.rating DESC;
