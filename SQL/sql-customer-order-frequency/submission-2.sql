-- Write your query below
SELECT c.customer_id, c.name 
FROM customers c
LEFT JOIN orders o ON c.customer_id = o.customer_id 
LEFT JOIN product p ON p.product_id = o.product_id
WHERE o.order_date >= '2020-06-01' AND o.order_date < '2020-08-01'
GROUP BY c.customer_id, c.name
HAVING SUM(CASE WHEN o.order_date >= '2020-06-01' AND o.order_date < '2020-07-01' THEN o.quantity * p.price ELSE 0 END) >= 100 AND SUM(CASE WHEN o.order_date >= '2020-07-01' AND o.order_date < '2020-08-01' THEN o.quantity * p.price ELSE 0 END) >= 100