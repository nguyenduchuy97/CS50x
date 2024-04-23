SELECT title
FROM movies
WHERE id =
(
    SELECT person_id
    FROM stars
    WHERE
    (
    SELECT name
    FROM people
    WHERE name = "Bradley Cooper"
    OR name = "Jennifer Lawrence"
    )
)
