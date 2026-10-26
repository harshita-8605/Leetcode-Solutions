# Write your MySQL query statement below
SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y' OR (employee_id, 1) IN (
    SELECT employee_id, COUNT(*) AS no_of_depts
    FROM Employee
    GROUP BY employee_id
)
