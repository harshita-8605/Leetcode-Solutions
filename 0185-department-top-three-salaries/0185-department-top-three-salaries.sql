# Write your MySQL query statement below

SELECT Department, Employee, Salary
FROM(
    SELECT D.name AS Department, E.name AS Employee, E.salary AS Salary,
        DENSE_RANK() OVER(PARTITION BY D.name ORDER BY E.salary DESC) AS Ranking
    FROM Employee AS E
    INNER JOIN Department AS D
    ON E.departmentId = D.id
    ORDER BY D.name ASC, E.salary DESC
) AS Ranked
WHERE Ranking <=3

-- D.name AS Department, E.name AS Employee, E.salary AS Salary

-- | id | name  | salary | departmentId | id | name  |
-- | -- | ----- | ------ | ------------ | -- | ----- |
-- | 4  | Max   | 90000  | 1            | 1  | IT    |
-- | 1  | Joe   | 85000  | 1            | 1  | IT    |
-- | 6  | Randy | 85000  | 1            | 1  | IT    |
-- | 7  | Will  | 70000  | 1            | 1  | IT    |
-- | 5  | Janet | 69000  | 1            | 1  | IT    |
-- | 2  | Henry | 80000  | 2            | 2  | Sales |
-- | 3  | Sam   | 60000  | 2            | 2  | Sales |