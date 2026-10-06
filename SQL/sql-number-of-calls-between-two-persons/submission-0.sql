-- Write your query below
SELECT (
    CASE WHEN from_id < to_id THEN from_id ELSE to_id END
) AS person1,
(
    CASE WHEN from_id > to_id THEN from_id ELSE to_id END
) AS person2,
COUNT(*) AS call_count,
COALESCE(SUM(duration),0) AS total_duration
FROM calls
GROUP BY person1, person2