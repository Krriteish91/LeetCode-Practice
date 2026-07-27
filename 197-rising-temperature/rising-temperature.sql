SELECT a.id
FROM Weather as a
LEFT JOIN Weather as b
ON DATE_SUB(a.recordDate, INTERVAL 1 DAY) = b.recordDate
where b.temperature < a.temperature