-- Write your query below
-- SELECT o.customer_id, o.product_id, p.product_name
-- FROM (
--     WITH counted AS (
--     SELECT customer_id, product_id, COUNT(*) as c
--     FROM orders
--     GROUP BY customer_id, product_id)
--     SELECT *, RANK() OVER (
--         PARTITION BY customer_id
--         ORDER BY c DESC
--     ) AS rn
--     FROM counted
-- ) o
-- JOIN products p ON p.product_id = o.product_id
-- WHERE o.rn = 1 AND c != 0
SELECT customer_id, product_id, product_name
FROM (
    SELECT
        o.customer_id,
        o.product_id,
        p.product_name,
        RANK() OVER (PARTITION BY o.customer_id ORDER BY COUNT(*) DESC) AS rnk
    FROM orders o
    JOIN customers c ON o.customer_id = c.customer_id
    JOIN products p ON o.product_id = p.product_id
    GROUP BY o.customer_id, o.product_id, p.product_name
) temp
WHERE rnk = 1
ORDER BY customer_id, product_id;

