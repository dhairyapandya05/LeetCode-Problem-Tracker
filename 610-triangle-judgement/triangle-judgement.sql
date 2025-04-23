# Write your MySQL query statement below
select x,y,z,CASE WHEN x+y>z AND
z+y>x AND
x+z>y THEN 'Yes' 
ELSE 'No' END as triangle
FROM Triangle
