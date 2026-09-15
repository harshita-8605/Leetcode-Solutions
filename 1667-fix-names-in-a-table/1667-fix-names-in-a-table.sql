# Write your MySQL query statement below
SELECT user_id, 
    CONCAT(UPPER(LEFT(NAME, 1)), LOWER(RIGHT(name,LENGTH(NAME)-1))) AS name
FROM Users
ORDER BY USER_ID