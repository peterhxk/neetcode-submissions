-- Write your query below
SELECT 
    user_id,
    MAX(gap) AS biggest_window
FROM (
    SELECT
        user_id,
        COALESCE(
            LEAD(visit_date) OVER (PARTITION BY user_id ORDER BY visit_date),
            '2021-01-01'::DATE) - visit_date AS gap
    FROM user_visits
) AS gaps
GROUP BY user_id
ORDER BY user_id