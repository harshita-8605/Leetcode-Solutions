# Write your MySQL query statement below
SELECT person_name
FROM(
    SELECT *, 
    SUM(Weight) OVER (ORDER BY turn ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW) AS `Total Weight`
    FROM Queue
) AS Q
WHERE `Total Weight` <= 1000
ORDER BY turn DESC
LIMIT 1

