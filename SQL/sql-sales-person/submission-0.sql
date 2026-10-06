-- Write your query below
SELECT s.name
FROM sales_person s
WHERE s.sales_id NOT IN (
    SELECT o.sales_id FROM orders o
    WHERE o.com_id IN (
        SELECT c.com_id FROM company c
        WHERE c.name = 'CRIMSON'
        )
)