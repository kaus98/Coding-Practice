-- Table: Logs

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | num         | varchar |
-- +-------------+---------+
-- id is the primary key for this table.
-- id is an autoincrement column.

 

-- Write an SQL query to find all numbers that appear at least three times consecutively.

-- Return the result table in any order.

-- The query result format is in the following example.

 

-- Example 1:

-- Input: 
-- Logs table:
-- +----+-----+
-- | id | num |
-- +----+-----+
-- | 1  | 1   |
-- | 2  | 1   |
-- | 3  | 1   |
-- | 4  | 2   |
-- | 5  | 1   |
-- | 6  | 2   |
-- | 7  | 2   |
-- +----+-----+
-- Output: 
-- +-----------------+
-- | ConsecutiveNums |
-- +-----------------+
-- | 1               |
-- +-----------------+
-- Explanation: 1 is the only number that appears consecutively for at least three times.




SELECT distinct Num as ConsecutiveNums
FROM Logs
WHERE (Id + 1, Num) in (select * from Logs) and (Id + 2, Num) in (select * from Logs)


SELECT 
    DISTINCT l1num as ConsecutiveNums  
FROM (
    SELECT 
        l1.id as l1id, 
        l2.id as l2id, 
        l3.id as l3id, 
        l1.num as l1num, 
        l2.num as l2num, 
        l3.num as l3num
    FROM Logs l1
        INNER JOIN Logs l2 ON l1.id = l2.id-1
        INNER JOIN Logs l3 ON l2.id = l3.id-1
    HAVING l1num = l2num AND l2num = l3num
    ) lin