-- Write your query below
SELECT seller_name
FROM seller s
WHERE s.seller_id NOT IN (SELECT seller_id FROM orders o WHERE o.sale_date>= '2020-01-01' AND o.sale_date <= '2020-12-31')
ORDER BY seller_name