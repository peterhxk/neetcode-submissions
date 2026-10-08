-- Write your query below
SELECT id, name
FROM students s
WHERE NOT EXISTS (SELECT 1 FROM  departments d where d.id = s.department_id)