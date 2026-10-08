-- Write your query below
WITH not_clean AS(
    SELECT p.project_id, e.employee_id, (
        RANK() OVER (
            PARTITION BY p.project_id
            ORDER BY e.experience_years DESC
        )
    ) AS rn
FROM project p
JOIN employee e ON p.employee_id = e.employee_id
)
SELECT project_id, employee_id
FROM not_clean
WHERE rn = 1
