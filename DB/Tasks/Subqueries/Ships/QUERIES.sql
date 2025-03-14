USE Ships

-- Напишете заявка, която извежда страните, чиито кораби са с най-голям брой оръдия
SELECT DISTINCT Classes.country FROM Classes
WHERE Classes.numguns=(
	SELECT MAX(Classes.numguns) FROM Classes
)

-- Напишете заявка, която извежда класовете, за които поне един от корабите е потънал в битка
SELECT DISTINCT Classes.class FROM Classes
JOIN Ships
ON Ships.class=Classes.class
JOIN Outcomes
ON Outcomes.ship=Ships.name
WHERE Ships.name IN (
	SELECT Outcomes.ship FROM Outcomes
	WHERE Outcomes.result='sunk'
)

-- Напишете заявка, която извежда името и класа на корабите с 16 инчови оръдия
SELECT Ships.name, Classes.class FROM Ships
JOIN Classes
ON Classes.class=Ships.class
WHERE Classes.bore=16

-- Напишете заявка, която извежда имената на битките, в които са участвали кораби от клас ‘Kongo’
SELECT DISTINCT Outcomes.battle FROM Classes
JOIN Ships
ON Ships.class=Classes.class
JOIN Outcomes
ON Outcomes.ship=Ships.name
WHERE Classes.class='Kongo'

-- Напишете заявка, която извежда класа и името на корабите, чиито брой
-- оръдия е по-голям или равен на този на корабите със същия калибър оръдия
SELECT S.class, S.name
FROM Ships S
JOIN Classes C1 ON S.class = C1.class
WHERE C1.numguns >= (
    SELECT MAX(C2.numguns)
    FROM Classes C2
    WHERE C1.bore = C2.bore
)
