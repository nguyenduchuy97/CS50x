SELECT name
FROM people
WHERE id =
(
    SELECT person_id
    FROM stars
    WHERE movie_id =
    (
        SELECT movie_id
        FROM ratings
    )
)
