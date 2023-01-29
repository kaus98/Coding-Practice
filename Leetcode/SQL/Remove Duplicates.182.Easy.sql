-- Table: Person

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | email       | varchar |
-- +-------------+---------+
-- id is the primary key column for this table.
-- Each row of this table contains an email. The emails will not contain uppercase letters.

 

-- Write an SQL query to report all the duplicate emails.

-- Return the result table in any order.

-- The query result format is in the following example.

 

-- Example 1:

-- Input: 
-- Person table:
-- +----+---------+
-- | id | email   |
-- +----+---------+
-- | 1  | a@b.com |
-- | 2  | c@d.com |
-- | 3  | a@b.com |
-- +----+---------+
-- Output: 
-- +---------+
-- | Email   |
-- +---------+
-- | a@b.com |
-- +---------+
-- Explanation: a@b.com is repeated two times.


-- Implemented These
SELECT email FROM (SELECT email, count(email) as ce FROM Person
GROUP BY email) cm
WHERE cm.ce > 1

SELECT email from Person
group by email
having count(email) > 1;

-- Checked from Solution

SELECT DISTINCT(p1.email) from Person p1, Person p2
where p1.id <> p2.id AND p1.email = p2.email;

SELECT DISTINCT(p1.email) from 
Person p1 JOIN Person p2 ON
p1.email = p2.email AND p1.id <> p2.id;