# Write your MySQL query statement below
SELECT W2.id
FROM Weather W1 INNER join Weather W2
ON w1.recordDate = DATE_SUB(W2.recordDate, INTERVAL 1 DAY)
WHERE W2.temperature > W1.temperature