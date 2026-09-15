# Write your MySQL query statement below
WITH person_name AS(
    SELECT U.name AS Name
    FROM MovieRating AS MR
        LEFT JOIN Movies AS M ON MR.movie_id = M.movie_id
        LEFT JOIN Users AS U ON MR.user_id = U.user_id
    GROUP BY U.name
    ORDER BY Count(MR.movie_id) DESC, U.name ASC
    LIMIT 1
),

movie_name AS(
    SELECT M.title AS Movie
    FROM MovieRating AS MR
        LEFT JOIN Movies AS M ON MR.movie_id = M.movie_id
    WHERE YEAR(MR.created_at) = 2020 && MONTH(MR.created_at) = 2
    GROUP BY M.title
    ORDER BY AVG(rating) DESC, M.title ASC
    LIMIT 1
)

SELECT Name AS results FROM person_name
UNION ALL
SELECT Movie FROM movie_name


-- | movie_id | user_id | rating | created_at | movie_id | title    | user_id | name   |
-- | -------- | ------- | ------ | ---------- | -------- | -------- | ------- | ------ |
-- | 1        | 1       | 3      | 2020-01-12 | 1        | Avengers | 1       | Daniel |
-- | 1        | 2       | 4      | 2020-02-11 | 1        | Avengers | 2       | Monica |
-- | 1        | 3       | 2      | 2020-02-12 | 1        | Avengers | 3       | Maria  |
-- | 1        | 4       | 1      | 2020-01-01 | 1        | Avengers | 4       | James  |
-- | 2        | 1       | 5      | 2020-02-17 | 2        | Frozen 2 | 1       | Daniel |
-- | 2        | 2       | 2      | 2020-02-01 | 2        | Frozen 2 | 2       | Monica |
-- | 2        | 3       | 2      | 2020-03-01 | 2        | Frozen 2 | 3       | Maria  |
-- | 3        | 1       | 3      | 2020-02-22 | 3        | Joker    | 1       | Daniel |
-- | 3        | 2       | 4      | 2020-02-25 | 3        | Joker    | 2       | Monica |