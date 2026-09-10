# Write your MySQL query statement below
/*
SELECT S.user_id, COUNT(*) AS Total_requests
FROM Signups AS S
    LEFT JOIN Confirmations AS C
    ON S.user_id = C.user_id
GROUP BY S.user_id

SELECT C.user_id, COUNT(*) AS Confirmed_requests
FROM Signups AS S
    LEFT JOIN Confirmations AS C
    ON S.user_id = C.user_id
GROUP BY C.user_id, C.action 
HAVING C.action = 'confirmed';
*/

SELECT Tr.user_id, round(COALESCE(Confirmed_requests,0)/Total_requests,2) AS confirmation_rate
FROM(
    SELECT S.user_id, COUNT(*) AS Total_requests
    FROM Signups AS S
    LEFT JOIN Confirmations AS C
    ON S.user_id = C.user_id
    GROUP BY S.user_id
) AS Tr
LEFT JOIN (
    SELECT C.user_id, COUNT(*) AS Confirmed_requests
    FROM Signups AS S
    LEFT JOIN Confirmations AS C
    ON S.user_id = C.user_id
    GROUP BY C.user_id, C.action 
    HAVING C.action = 'confirmed'
) AS Cr 
ON Tr.user_id = Cr.user_id