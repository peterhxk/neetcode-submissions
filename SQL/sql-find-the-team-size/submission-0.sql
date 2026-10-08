-- Write your query below
SELECT e1.employee_id, (
    COUNT(e1.team_id = e2.team_id)
)AS team_size
FROM employee e1
JOIN employee e2 ON e1.team_id = e2.team_id
GROUP BY e1.employee_id
