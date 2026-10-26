# Write your MySQL query statement below
SELECT customer_id
FROM (
    SELECT customer_id, COUNT(DISTINCT product_key) AS cnt
    FROM Customer
    GROUP BY customer_id
) AS T1
WHERE cnt = (
    SELECT COUNT(*) FROM PRODUCT
)

