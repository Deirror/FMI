USE Ships

-- Напишете заявка, която извежда цялата налична информация за всеки кораб, 
-- включително и данните за неговия клас. В резултата не трябва да 
-- се включват тези класове, които нямат кораби
SELECT * FROM Ships
RIGHT JOIN Classes
ON Classes.class=Ships.class
WHERE Ships.class IS NOT NULL

-- Повторете горната заявка, като този път включите в резултата и класовете, 
-- които нямат кораби, но съществуват кораби със същото име като тяхното
SELECT * FROM Ships S1
RIGHT JOIN Classes C1
ON C1.class=S1.class
WHERE (
	SELECT COUNT(S2.name) FROM Ships S2 WHERE S2.name=C1.class
) >= 1

-- За всяка страна изведете имената на корабите, които никога не са участвали в битка
SELECT Classes.country, Ships.name FROM Ships
JOIN Classes
ON Classes.class=Ships.class
WHERE Ships.name NOT IN (
SELECT Outcomes.ship FROM Outcomes
)
ORDER BY Classes.country

-- Намерете имената на всички кораби с поне 7 оръдия, пуснати на вода през 
-- 1916, но наречете резултатната колона Ship Name
SELECT Ships.name AS 'Ship Name' FROM Ships
JOIN Classes
ON Classes.class=Ships.class
WHERE Classes.numguns >= 7 AND Ships.launched=1916

-- Изведете имената на всички потънали в битка кораби, името и дата на 
-- провеждане на битките, в които те са потънали. Подредете резултата по име на битката
SELECT Outcomes.ship, Battles.name, Battles.date FROM Outcomes
JOIN Battles
ON Battles.name=Outcomes.battle
WHERE Outcomes.result='sunk'
ORDER BY Battles.name

-- Намерете името, водоизместимостта и годината на пускане на вода на 
-- всички кораби, които имат същото име като техния клас
SELECT Ships.name, Classes.displacement, Ships.launched FROM Classes
JOIN Ships
ON Ships.class=Classes.class
WHERE Classes.class=Ships.name

-- Намерете всички класове кораби, от които няма пуснат на вода нито един кораб
SELECT * FROM Ships
RIGHT JOIN Classes
ON Classes.class=Ships.class
WHERE Ships.class IS NULL

-- Изведете името, водоизместимостта и броя оръдия на корабите,
-- участвали в битката ‘North Atlantic’, а също и резултата от битката
SELECT Ships.name, Classes.displacement, Classes.numguns, Outcomes.result FROM Ships
JOIN Classes
ON Classes.class=Ships.class
JOIN Outcomes
ON Outcomes.ship=Ships.name
WHERE Outcomes.battle='North Atlantic'
