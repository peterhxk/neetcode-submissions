-- Write your query below
WITH RECURSIVE subtasks AS (
    SELECT task_id, 1 AS subtask_id
    FROM tasks
    UNION ALL
    SELECT 
        t.task_id,
        s.subtask_id+1
    FROM tasks t
    JOIN subtasks s ON t.task_id = s.task_id
    WHERE s.subtask_id < t.subtasks_count 
)
SELECT task_id, subtask_id
FROM subtasks
WHERE (task_id, subtask_id) NOT IN (
    SELECT task_id, subtask_id FROM executed
)