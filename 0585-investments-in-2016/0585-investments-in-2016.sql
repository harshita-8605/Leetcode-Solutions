# Write your MySQL query statement below
SELECT ROUND(SUM(tiv_2016),2) AS tiv_2016
FROM Insurance AS I
WHERE I.TIV_2015 IN(
    SELECT tiv_2015
    FROM Insurance
    WHERE pid != I.pid
) && 
(I.lat, I.lon) NOT IN(
    SELECT lat, lon
    FROM Insurance
    WHERE pid != I.pid
)