/* Write your T-SQL query statement below */
SELECT Em.unique_id, e.name
FROM Employees AS e
LEFT JOIN EmployeeUNI AS Em
ON e.ID=Em.id
