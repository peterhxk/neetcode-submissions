-- Write your query below
WITH removed AS (
    SELECT DISTINCT student_id FROM
    (SELECT *, RANK() OVER (
        PARTITION BY exam_id
        ORDER BY score DESC
    ) AS top_down_rn,
     RANK() OVER (
        PARTITION BY exam_id
        ORDER BY score ASC
    ) AS bottom_up_rn
    FROM exam
    )
    WHERE top_down_rn = 1 OR bottom_up_rn = 1
),
students AS (SELECT DISTINCT student_id FROM exam)
SELECT s.student_id, s.student_name
FROM student s
WHERE s.student_id IN (SELECT student_id FROM students) AND s.student_id NOT IN (SELECT student_id FROM removed)