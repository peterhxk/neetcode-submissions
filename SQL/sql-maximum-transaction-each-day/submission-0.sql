-- Write your query below
SELECT transaction_id
FROM (SELECT *, RANK() OVER (
    PARTITION BY EXTRACT(day FROM day) ORDER BY amount DESC
) AS rn FROM transactions)
WHERE rn = 1
ORDEr BY transaction_id 