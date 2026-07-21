select a.name 
from Employee as a
join Employee as b
on a.id = b.managerId
group by a.name,a.id
having count(b.managerId) >= 5
