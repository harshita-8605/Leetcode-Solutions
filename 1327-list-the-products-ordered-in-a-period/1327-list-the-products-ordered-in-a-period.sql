# Write your MySQL query statement below
SELECT product_name, SUM(unit) AS unit
FROM Orders AS O
LEFT JOIN Products AS P
ON O.product_id = P.product_id
WHERE YEAR(O.order_date) = 2020 && MONTH(O.order_date) = 2 
GROUP BY product_name
HAVING SUM(unit) >=100


-- | product_id | order_date | unit | product_id | product_name          | product_category |
-- | ---------- | ---------- | ---- | ---------- | --------------------- | ---------------- |
-- | 1          | 2020-02-05 | 60   | 1          | Leetcode Solutions    | Book             |
-- | 1          | 2020-02-10 | 70   | 1          | Leetcode Solutions    | Book             |
-- | 2          | 2020-01-18 | 30   | 2          | Jewels of Stringology | Book             |
-- | 2          | 2020-02-11 | 80   | 2          | Jewels of Stringology | Book             |
-- | 3          | 2020-02-17 | 2    | 3          | HP                    | Laptop           |
-- | 3          | 2020-02-24 | 3    | 3          | HP                    | Laptop           |
-- | 4          | 2020-03-01 | 20   | 4          | Lenovo                | Laptop           |
-- | 4          | 2020-03-04 | 30   | 4          | Lenovo                | Laptop           |
-- | 4          | 2020-03-04 | 60   | 4          | Lenovo                | Laptop           |
-- | 5          | 2020-02-25 | 50   | 5          | Leetcode Kit          | T-shirt          |
-- | 5          | 2020-02-27 | 50   | 5          | Leetcode Kit          | T-shirt          |
-- | 5          | 2020-03-01 | 50   | 5          | Leetcode Kit          | T-shirt          |