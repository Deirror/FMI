USE Ships

-- Напишете заявка, която извежда името на корабите с водоизместимост над 50000
SELECT name FROM Ships
JOIN Classes
ON Ships.class=Classes.class
WHERE Classes.displacement>50000

-- Напишете заявка, която извежда имената, водоизместимостта и броя оръдия на всички кораби, участвали в битката при Guadalcanal
SELECT Ships.name, Classes.displacement, Classes.numguns FROM Outcomes
JOIN Ships
ON Ships.name=Outcomes.ship
JOIN Classes
ON Ships.class=Classes.class
JOIN Battles
ON Battles.name=Outcomes.battle
WHERE Battles.name='Guadalcanal'

-- Напишете заявка, която извежда имената на тези държави, които имат както бойни кораби, така и бойни крайцери
SELECT country FROM Classes GROUP BY country HAVING COUNT(DISTINCT type) = 2

-- Напишете заявка, която извежда имената на тези кораби, които са били повредени в една битка, но по-късно са участвали в друга битка
SELECT DISTINCT S.name
FROM Ships S
JOIN Outcomes O1 ON S.name = O1.ship
JOIN Battles B1 ON O1.battle = B1.name
JOIN Outcomes O2 ON S.name = O2.ship
JOIN Battles B2 ON O2.battle = B2.name
WHERE O1.result = 'damaged'
AND B1.date < B2.date;
