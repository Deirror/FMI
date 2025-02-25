USE Ships

-- Напишете заявка, която извежда класа и страната за всички класове с помалко от 10 оръдия.
SELECT class, country FROM Classes WHERE numguns < 10

-- Напишете заявка, която извежда имената на корабите, пуснати на вода преди 1918. Задайте псевдоним shipName на колоната.
SELECT name AS shipName FROM Ships WHERE launched < 1918

-- Напишете заявка, която извежда имената на корабите потънали в битка и имената на съответните битки.
SELECT ship, battle FROM Outcomes WHERE result='sunk'

-- Напишете заявка, която извежда имената на корабите с име, съвпадащо с името на техния клас.
SELECT name FROM Ships WHERE class=name

-- Напишете заявка, която извежда имената на корабите, които започват с буквата R.
SELECT name FROM Ships WHERE name LIKE 'R%'

-- Напишете заявка, която извежда имената на корабите, които съдържат 2 или повече думи.
SELECT name FROM Ships WHERE name LIKE '% %'
