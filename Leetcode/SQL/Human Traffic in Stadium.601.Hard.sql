-- Table: Stadium

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | id            | int     |
-- | visit_date    | date    |
-- | people        | int     |
-- +---------------+---------+
-- visit_date is the primary key for this table.
-- Each row of this table contains the visit date and visit id to the stadium with the number of people during the visit.
-- No two rows will have the same visit_date, and as the id increases, the dates increase as well.

 

-- Write an SQL query to display the records with three or more rows with consecutive id's, and the number of people is greater than or equal to 100 for each.

-- Return the result table ordered by visit_date in ascending order.

-- The query result format is in the following example.

 

-- Example 1:

-- Input: 
-- Stadium table:
-- +------+------------+-----------+
-- | id   | visit_date | people    |
-- +------+------------+-----------+
-- | 1    | 2017-01-01 | 10        |
-- | 2    | 2017-01-02 | 109       |
-- | 3    | 2017-01-03 | 150       |
-- | 4    | 2017-01-04 | 99        |
-- | 5    | 2017-01-05 | 145       |
-- | 6    | 2017-01-06 | 1455      |
-- | 7    | 2017-01-07 | 199       |
-- | 8    | 2017-01-09 | 188       |
-- +------+------------+-----------+
-- Output: 
-- +------+------------+-----------+
-- | id   | visit_date | people    |
-- +------+------------+-----------+
-- | 5    | 2017-01-05 | 145       |
-- | 6    | 2017-01-06 | 1455      |
-- | 7    | 2017-01-07 | 199       |
-- | 8    | 2017-01-09 | 188       |
-- +------+------------+-----------+
-- Explanation: 
-- The four rows with ids 5, 6, 7, and 8 have consecutive ids and each of them has >= 100 people attended. Note that row 8 was included even though the visit_date was not the next day after row 7.
-- The rows with ids 2 and 3 are not included because we need at least three consecutive ids.




# Write your MySQL query statement below


// Simplest Solution
WITH temp_data AS (SELECT id FROM Stadium WHERE people > 100)

SELECT * FROM Stadium
WHERE id in (SELECT id FROM temp_data)
    AND (
            (
                (id+1 in (SELECT id FROM temp_data) AND id+2 in (SELECT id FROM temp_data))
                OR 
                (id+1 in (SELECT id FROM temp_data) AND id-1 in (SELECT id FROM temp_data))
            )
            OR 
            (id-1 in (SELECT id FROM temp_data) AND id-2 in (SELECT id FROM temp_data))
        )


// We will collect the rows which have same lag by substracting id from row_number

WITH temp_data as (
SELECT  *, id - row_number() over() AS id_diff
FROM stadium
WHERE people > 99
)

SELECT id, visit_date, people
FROM temp_data
WHERE id_diff IN (SELECT id_diff AS cid FROM temp_data GROUP BY id_diff HAVING COUNT(*) > 2)

//With Lag and Lead

WITH temp2  AS 
(
    SELECT
        *,
        (LAG(id) OVER()) + 1 AS "prev1",
        (LAG(id,2) OVER()) + 2 AS "prev2",
        (LEAD(id) OVER()) - 1 AS "next1", 
        (LEAD(id,2) OVER()) - 2 AS "next2"
    FROM  
        (SELECT * FROM Stadium WHERE people > 99) temp1
)

SELECT id, visit_date, people  FROM temp2
WHERE 
    (id = prev1 AND id = prev2)
    OR (id = prev1 AND id = next1)
    OR (id = next2 AND id = next1)