# Write your MySQL query statement below

SELECT ES.employee_id
FROM(
    SELECT * 
    FROM EMPLOYEES
    WHERE SALARY<30000
) AS ES
WHERE ES.manager_id NOT IN(
    SELECT employee_id FROM Employees
)
ORDER BY ES.employee_id ASC

