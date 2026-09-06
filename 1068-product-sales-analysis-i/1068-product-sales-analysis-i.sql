# Write your MySQL query statement below
SELECT product_name, year, price
FROM Sales AS S INNER JOIN Product AS P ON s.product_id = P.product_id;