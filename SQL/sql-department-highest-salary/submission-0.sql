-- Write your query below
SELECT d.name AS department, e.name AS employee, e.salary
FROM (
    SELECT *, (
    RANK() OVER (
        PARTITION BY department_id
        ORDER BY salary DESC
    )) as rn
    FROM employee
) e
JOIN department d ON e.department_id = d.id
WHERE rn = 1