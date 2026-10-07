-- Write your query below
WITH friends AS (
    SELECT CASE WHEN user1_id = 1 THEN user2_id WHEN user2_id = 1 THEN user1_id
    END AS username
    FROM friendship
), liked AS (
    SELECT DISTINCT page_id FROM likes WHERE user_id = 1
)
SELECT DISTINCT l.page_id as recommended_page
FROM likes l
WHERE l.user_id IN (SELECT username FROM friends) AND l.page_id NOT IN (SELECT page_id FROM liked)
ORDER BY l.page_id
