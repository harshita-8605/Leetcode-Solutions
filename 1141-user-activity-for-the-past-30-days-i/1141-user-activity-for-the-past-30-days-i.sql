# Write your MySQL query statement below
SELECT A.activity_date AS day , COUNT(A.user_id) AS active_users
FROM(
    SELECT user_id, activity_date
    FROM Activity
    GROUP BY activity_date, user_id
    HAVING activity_date BETWEEN '2019-06-28' AND '2019-07-27'
) AS A
GROUP BY A.activity_date
