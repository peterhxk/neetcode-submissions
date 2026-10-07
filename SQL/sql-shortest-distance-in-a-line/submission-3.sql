-- Write your query below
WITH ordered AS (
    SELECT x
    FROM point
    ORDER BY x
),
 gaps AS (
    SELECT x, LAG(x) OVER (ORDER BY x) AS previous_x
    FROM ordered
)
SELECT MIN(x - previous_x) AS shortest
FROM gaps