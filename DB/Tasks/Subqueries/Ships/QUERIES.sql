USE Ships

-- Напишете заявка, която извежда страните, чиито кораби са с най-голям брой оръдия
SELECT DISTINCT Classes.country FROM Classes
WHERE Classes.numguns=(
	SELECT MAX(Classes.numguns) FROM Classes
)
