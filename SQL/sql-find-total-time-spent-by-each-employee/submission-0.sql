-- Write your query below
SELECT event_day as day, emp_id, 
COALESCE(SUM(out_time-in_time),0) as total_time
FROM employees
GROUP BY event_day, emp_id