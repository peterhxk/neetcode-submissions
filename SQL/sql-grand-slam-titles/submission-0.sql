-- Write your query below
WITH wins AS (
SELECT player_id, player_name, 
COALESCE((SELECT COUNT(*) FROM championships WHERE fr_open = player_id) + (SELECT COUNT(*)FROM championships WHERE wimbledon = player_id)+(SELECT COUNT(*) FROM championships WHERE us_open = player_id)+(SELECT COUNT(*) FROM championships WHERE au_open = player_id),0) AS grand_slams_count
FROM players
)
SELECT player_id, player_name, grand_slams_count
FROM wins
WHERE grand_slams_count > 0