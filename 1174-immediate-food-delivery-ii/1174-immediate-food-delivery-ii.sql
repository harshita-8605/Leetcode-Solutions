# Write your MySQL query statement below
# https://www.youtube.com/watch?v=I-38YxAIwK0

SELECT 
    ROUND(COUNT(*)/(SELECT COUNT(DISTINCT(customer_id)) FROM Delivery) *100, 2) AS immediate_percentage
FROM Delivery
WHERE customer_pref_delivery_date = order_date AND (customer_id, order_date) IN (
    SELECT customer_id , MIN(order_date) AS first_order
    FROM Delivery
    GROUP BY customer_id
);