# Write your MySQL query statement below
SELECT name
FROM Employee AS E INNER JOIN (
    SELECT managerId
    FROM 
    Employee AS E
    GROUP BY managerId
    HAVING COUNT(managerId) >= 5
) AS M ON E.id = M.managerId;

