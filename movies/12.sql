SELECT title
FROM movies
WHERE id IN
(
    SELECT movie_id
    FROM stars
    WHERE person_id =
    (
        SELECT id
        FROM people
        WHERE name = "Bradley Cooper"
    )
    AND movies.id IN
    (
        SELECT movie_id
        FROM stars
        WHERE person_id =
        (
            SELECT id
            FROM people
            WHERE name = "Jennifer Lawrence"
        )
    )
);
