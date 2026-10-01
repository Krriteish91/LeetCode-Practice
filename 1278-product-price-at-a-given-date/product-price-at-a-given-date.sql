select p.product_id , coalesce(new_price ,10) as price
from (select distinct product_id from Products) as p
left join (select product_id, new_price
from 
(select * ,ROW_NUMBER() over (partition by product_id order by change_date desc) as rn
from Products
where change_date <= '2019-08-16') t
where rn = 1) latest
on p.product_id = latest.product_id











