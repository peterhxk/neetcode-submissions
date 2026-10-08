-- Write your query below
SELECT p.product_name, p.product_id, o.order_id, o.order_date
FROM products p
JOIN (SELECT *, (
    RANK() OVER (
        PARTITION BY product_id
        ORDER BY order_date DESC
    ) )AS rn
    FROM orders) o ON p.product_id = o.product_id
WHERE rn = 1
ORDER BY product_name, product_id, order_id 