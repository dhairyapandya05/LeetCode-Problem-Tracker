/* Write your T-SQL query statement below */
SELECT v.customer_id,COUNT(v.visit_id) AS count_no_trans
FROM Visits AS v
LEFT JOIN Transactions AS t
ON v.visit_id=t.visit_id
WHERE t.visit_id IS NULL
GROUP by v.customer_id