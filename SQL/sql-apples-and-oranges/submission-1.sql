-- Write your query below
SELECT sale_date, COALESCE(SUM(CASE WHEN fruit = 'apples' THEN sold_num ELSE 0 END)
- SUM(CASE WHEN fruit = 'oranges' THEN sold_num ELSE 0 END),0) as diff
FROM sales

GROUP BY sale_date
ORDER BY sale_date