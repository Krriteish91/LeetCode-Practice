select round(sum(e.order_date = e.customer_pref_delivery_date)/count(*), 4)*100 as immediate_percentage 
from (
    select customer_id , min(order_date) as order_date
    from Delivery
    group by customer_id 
) as d
left join Delivery e
on d.customer_id = e.customer_id  and d.order_date = e.order_date



