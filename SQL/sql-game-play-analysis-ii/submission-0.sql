-- Write your query below
WITH ranked AS (
    SELECT
    *,
    ROW_NUMBER() OVER (
        PARTITION BY player_id
        ORDER BY event_date ASC
    ) AS rn
    FROM activity
)
SELECT player_id, device_id
FROM ranked
WHERE rn = 1