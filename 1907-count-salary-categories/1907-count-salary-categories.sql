# Write your MySQL query statement below
SELECT Different_Types.Salary_Category_Types AS category, COUNT(A.Salary_Category) AS accounts_count 
FROM(
    SELECT account_id, income, 
        CASE 
        WHEN income <20000 THEN 'Low Salary'
        WHEN income >= 20000 && income <= 50000 THEN 'Average Salary'
        ELSE 'High Salary' 
        END AS Salary_Category
    FROM Accounts
) AS A 
RIGHT JOIN (
    SELECT 'High Salary' AS 'Salary_Category_Types'
    UNION ALL 
    SELECT 'Average Salary'
    UNION ALL
    SELECT 'Low Salary'
) AS Different_Types
ON A.Salary_Category = Different_Types.Salary_Category_Types
GROUP BY Different_Types.Salary_Category_Types

