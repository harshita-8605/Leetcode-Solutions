# Write your MySQL query statement below
SELECT DISTINCT(num) AS ConsecutiveNums
FROM(
    SELECT *, LEAD(num,1) OVER() AS next, LEAD(num,2) OVER() AS next2next
    FROM Logs
) AS L
WHERE num = next && num = next2next;