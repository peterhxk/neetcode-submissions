-- Write your query below
SELECT DISTINCT c.title
FROM content c
LEFT JOIN tv_program t ON t.content_id = c.content_id
WHERE c.kids_content = 'Y'
AND t.program_date >= '2020-06-01' AND t.program_date < '2020-07-01'
AND c.content_type = 'Movies'