USE Ships

-- Напишете заявка, която извежда броя на класовете бойни кораби
SELECT COUNT(*) AS NO_Classes FROM Classes
WHERE Classes.type='bb'

-- Напишете заявка, която извежда средния брой оръдия за всеки клас боен кораб
SELECT Classes.class, AVG(Classes.numguns) AS AvgGuns FROM Classes
WHERE Classes.type='bb'
GROUP BY Classes.class

-- Напишете заявка, която извежда средния брой оръдия за всички бойни кораби
SELECT AVG(Classes.numguns) AS AvgGuns FROM Classes
WHERE Classes.type='bb'

-- Напишете заявка, която извежда за всеки клас първата и последната година, в
-- която кораб от съответния клас е пуснат на вода
SELECT Classes.class, MIN(Ships.launched) AS FirstYear, MAX(Ships.launched) AS LastYear FROM Classes
JOIN Ships
ON Ships.class=Classes.class
GROUP BY Classes.class

-- Напишете заявка, която извежда броя на корабите, потънали в битка според класа
SELECT Classes.class, COUNT(*) AS No_Sunk FROM Classes
JOIN Ships
ON Ships.class=Classes.class
JOIN Outcomes
ON Outcomes.ship=Ships.name
WHERE Outcomes.result='sunk'
GROUP BY Classes.class

-- Напишете заявка, която извежда броя на корабите, потънали в битка според
-- класа, за тези класове с повече от 2 кораба
SELECT Classes.class, COUNT(*) AS No_Sunk FROM Classes
JOIN Ships
ON Ships.class=Classes.class
JOIN Outcomes
ON Outcomes.ship=Ships.name
WHERE Outcomes.result='sunk'
AND (SELECT COUNT(*) FROM Ships WHERE Ships.class=Classes.class) >= 2
GROUP BY Classes.class

-- Напишете заявка, която извежда средния калибър на оръдията на корабите за всяка страна
SELECT Classes.country, ROUND(AVG(Classes.bore), 2) AS avg_bore FROM Classes
JOIN Ships ON Ships.class=Classes.class
GROUP BY Classes.country
