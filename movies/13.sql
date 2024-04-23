SELECT name
FROM people
WHERE id =
(
    SELECT person_id
    FROM stars
    WHERE person_id =
    (
        SELECT id
        FROM people
        WHERE name = "Kevin Bacon"
        AND birth = "1958"
    )
)
