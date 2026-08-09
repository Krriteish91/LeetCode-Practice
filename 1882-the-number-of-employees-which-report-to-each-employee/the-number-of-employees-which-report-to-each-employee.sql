select a.employee_id , a.name , count(b.reports_to) as reports_count , round(avg(b.age),0) as average_age 
from Employees as a
left join Employees as b
on a.employee_id = b.reports_to
group by a.employee_id , a.name
having count(b.reports_to) > 0
order by a.employee_id