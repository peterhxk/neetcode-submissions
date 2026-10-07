-- Write your query below
SELECT a.player_id, a.event_date, COALESCE((SELECT SUM(a2.games_played) FROM activity a2 WHERE a.player_id = a2.player_id AND a2.event_date <= a.event_date), 0)AS games_played_so_far
FROM activity a