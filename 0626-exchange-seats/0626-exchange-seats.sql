# Write your MySQL query statement below

SELECT S.id, 
    CASE
        WHEN S.next IS NULL && id%2 !=0 THEN S.student
        WHEN S.id%2 != 0 THEN S.next
        ELSE S.prev
        END AS student
FROM(
    SELECT *,
        LEAD(student,1) OVER () AS next,
        LAG(student,1) OVER() AS Prev
    FROM Seat
) AS S