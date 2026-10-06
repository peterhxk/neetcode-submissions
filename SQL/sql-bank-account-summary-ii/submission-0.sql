-- Write your query below
SELECT u.name,
COALESCE(SUM(t.amount),0) AS balance
FROM users u
LEFT JOIN transactions t ON u.account = t.account
GROUP BY u.name
HAVING COALESCE(SUM(t.amount),0) > 10000