# Write your MySQL query statement below
SELECT S.user_id,
    COALESCE(ROUND(SUM(CASE
        WHEN action = 'timeout' THEN 0
        WHEN action = 'confirmed' THEN 1
        WHEN action = NULL THEN 0
    END) / COUNT(*) , 2 ) , 0)AS confirmation_rate
FROM Signups AS S
LEFT JOIN Confirmations AS C
ON S.user_id = C.user_id
GROUP BY S.User_id