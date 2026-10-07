-- Write your query below
SELECT 
CASE WHEN e.employee_id is NULL THEN s.employee_id ELSE e.employee_id END AS employee_id
FROM employees e
FULL OUTER JOIN salaries s ON e.employee_id = s.employee_id
WHERE e.name is NULL OR s.salary is NULL