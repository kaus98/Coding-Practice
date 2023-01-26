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