-- Write your query below
SELECT e.*, 
    CASE WHEN ((operator = '<' AND l.value < r.value)
    OR (operator = '=' AND l.value = r.value)
    OR (operator = '>' AND l.value > r.value))
    THEN true
    ELSE false
    END AS value
FROM expressions e LEFT JOIN variables l ON left_operand = l.name 
LEFT JOIN variables r ON right_operand = r.name 