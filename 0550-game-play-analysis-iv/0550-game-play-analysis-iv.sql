# Write your MySQL query statement below
SELECT ROUND(COUNT(DISTINCT(A1.player_id))/(SELECT COUNT(DISTINCT(player_id)) FROM Activity) , 2) AS fraction
FROM 
    Activity AS A1 INNER JOIN Activity AS A2 
    ON A1.player_id = A2.player_id
        AND DATEDIFF(A2.event_date , A1.event_date) = 1
WHERE (A1.player_id, A1.event_date) IN(
    SELECT A3.player_id, MIN(A3.event_date)
    FROM Activity A3
    GROUP BY A3.player_id
)