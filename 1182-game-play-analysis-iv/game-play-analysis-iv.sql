select round(count(b.player_id)/count( distinct a.player_id),2) as fraction
from Activity as a
left join (
    select player_id , date_add(min(event_date) , interval 1 day) as event_date
    from Activity
    group by player_id
) as b
on a.player_id = b.player_id and a.event_date = b.event_date
