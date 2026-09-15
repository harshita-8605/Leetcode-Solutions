# Write your MySQL query statement below
# https://www.youtube.com/watch?v=aM9GEJCCoUw
SELECT C.visited_on,
    (
        SELECT SUM(amount)
        FROM Customer 
        WHERE visited_on BETWEEN DATE_SUB(C.visited_on, INTERVAL 6 DAY) AND C.visited_on
    ) AS amount,
    (
        SELECT ROUND(SUM(amount)/7,2)
        FROM Customer 
        WHERE visited_on BETWEEN DATE_SUB(C.visited_on, INTERVAL 6 DAY) AND C.visited_on
    ) AS average_amount


FROM Customer AS C
WHERE visited_on >= (
    SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY)
    FROM Customer
)
GROUP BY visited_on
ORDER BY visited_on ASC