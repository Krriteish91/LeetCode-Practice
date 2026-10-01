select person_name
from 
(select *, SUM(weight) over (order by turn rows between unbounded preceding and current row) as bus_weight
from Queue) t
where bus_weight <= 1000
order by bus_weight desc
limit 1


