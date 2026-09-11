# Write your MySQL query statement below
SELECT DISTINCT(reports_to) AS employee_id, 
    (SELECT name FROM Employees AS E1 WHERE E.reports_to = E1.employee_id) AS name,
    cnt AS reports_count, ROUND(average,0) AS average_age
FROM(
    SELECT reports_to, COUNT(*) AS cnt, AVG(age) AS average
    FROM Employees
    WHERE reports_to IS NOT NULL
    GROUP BY reports_to
) AS E
ORDER BY employee_id