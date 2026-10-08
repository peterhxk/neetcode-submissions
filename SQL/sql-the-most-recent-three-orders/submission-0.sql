-- Write your query below
SELECT c.name AS customer_name, o.customer_id, o.order_id, o.order_date
FROM (SELECT *, ROW_NUMBER() OVER (
    PARTITION BY customer_id
    ORDER BY order_date DESC
) AS rn
FROM orders) o
JOIN customers c ON c.customer_id = o.customer_id
WHERE rn <=3
ORDER BY customer_name, customer_id, order_date DESC