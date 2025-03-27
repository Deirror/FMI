USE Ships

-- Напишете заявка, която извежда имената на всички кораби без повторения,
-- които са участвали в поне една битка и чиито имена започват с C или K
SELECT DISTINCT Ships.name FROM Ships
WHERE Ships.name LIKE 'C%' OR Ships.name LIKE 'K%'
AND (
SELECT COUNT(Outcomes.ship) FROM Outcomes
WHERE SHips.name=Outcomes.ship
) >= 1

-- Напишете заявка, която извежда име и държава на всички кораби, които
-- никога не са потъвали в битка (може и да не са участвали)
SELECT DISTINCT Ships.name, Classes.country FROM Classes
JOIN Ships
ON Ships.class=Classes.class
LEFT JOIN Outcomes
ON Outcomes.ship=Ships.name
WHERE Outcomes.result!='sunk' OR Outcomes.result IS NULL

-- Напишете заявка, която извежда държавата и броя на потъналите кораби за
-- тази държава. Държави, които нямат кораби или имат кораб, но той не е
-- участвал в битка, също да бъдат изведени

SELECT DISTINCT Classes.country, COUNT(Outcomes.ship) AS num_sunk_ships FROM Classes
LEFT JOIN Ships
ON Ships.class=Classes.class
LEFT JOIN Outcomes
ON Outcomes.ship=Ships.name
WHERE Outcomes.result='sunk' OR Outcomes.result IS NULL
GROUP BY Classes.country

-- Напишете заявка, която извежда име на битките, които са по-мащабни (с
-- повече участващи кораби) от битката при Guadalcanal
SELECT DISTINCT Outcomes.battle FROM Outcomes
WHERE (SELECT COUNT(*) AS battles FROM Outcomes
WHERE Outcomes.battle='Guadalcanal') < (SELECT COUNT(*) AS battles FROM Outcomes O1
WHERE O1.battle=Outcomes.battle) AND Outcomes.battle!='Guadalcanal'

-- Напишете заявка, която извежда име на битките, които са по-мащабни (с
-- повече участващи страни) от битката при Surigao Strait
SELECT DISTINCT Outcomes.battle FROM Outcomes
WHERE (SELECT COUNT(*) AS battles FROM Outcomes
WHERE Outcomes.battle='Surigao Strait') < (SELECT COUNT(*) AS battles FROM Outcomes O1
WHERE O1.battle=Outcomes.battle) AND Outcomes.battle!='Surigao Strait'

-- Напишете заявка, която извежда имената на най-леките кораби с най-много оръдия
WITH MINDISP AS (
SELECT DISTINCT Ships.name, Classes.displacement, Classes.numguns FROM Classes
JOIN Ships
ON Ships.class=Classes.class
WHERE Classes.displacement=(
SELECT MIN(Classes.displacement) FROM Classes
)
) SELECT MINDISP.name, MINDISP.displacement, MINDISP.numguns FROM MINDISP
WHERE MINDISP.numguns=(
SELECT MAX(MINDISP.numguns) FROM MINDISP
)

-- Изведете броя на корабите, които са били увредени в битка, но са били
-- поправени и по-късно са победили в друга битка
SELECT COUNT(O1.ship) AS num_ships FROM Outcomes O1
JOIN Outcomes O2
ON O2.ship=O1.ship
WHERE O1.result='damaged' AND O2.result='ok'

-- Изведете име на корабите, които са били увредени в битка, но са били
-- поправени и по-късно са победили в по-мащабна битка (с повече кораби)
SELECT O1.ship FROM Outcomes O1
JOIN Outcomes O2
ON O2.ship=O1.ship
WHERE O1.result='damaged' AND O2.result='ok'
AND (
SELECT COUNT(*) FROM Outcomes O3
WHERE O3.battle=O2.battle
)=(
SELECT TOP 1 COUNT(*) as cnt FROM Outcomes O3
GROUP BY O3.battle
ORDER BY cnt DESC
)
