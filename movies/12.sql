SELECT title
FROM movies
WHERE id =
(
    SELECT movie_id
    FROM stars
    WHERE person_id =
    (
    SELECT id
    FROM people
    WHERE name = "Bradley Cooper"
    AND name = "Jennifer Lawrence"
    )
);
