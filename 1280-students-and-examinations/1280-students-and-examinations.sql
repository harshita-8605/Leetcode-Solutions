SELECT 
    S.student_id, 
    S.student_name, 
    Su.subject_name, 
    COUNT(E.subject_name) AS attended_exams
FROM Students AS S
CROSS JOIN Subjects AS Su
LEFT JOIN Examinations AS E 
    ON S.student_id = E.student_id
    AND Su.subject_name = E.subject_name
GROUP BY 
    S.student_id, 
    S.student_name, 
    Su.subject_name
ORDER BY 
    S.student_id, 
    Su.subject_name;