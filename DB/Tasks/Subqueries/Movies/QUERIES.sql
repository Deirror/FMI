USE Movies

-- Напишете заявка, която извежда имената на актрисите, които са също и продуценти с нетни активи над 10 милиона
SELECT MovieStar.name FROM MovieStar
WHERE MovieStar.gender='F' AND MovieStar.name IN (
	  SELECT MovieExec.name FROM MovieExec 
    WHERE MovieExec.networth > 10000000
)

-- Напишете заявка, която извежда имената на тези актьори (мъже и жени), които не са продуценти
SELECT MovieStar.name FROM MovieStar
WHERE MovieStar.name NOT IN (
	  SELECT MovieExec.name FROM MovieExec
)

-- Напишете заявка, която извежда имената на всички филми с дължина, по-голяма от дължината на филма ‘Star Wars’
SELECT Movie.title FROM Movie
WHERE Movie.length > (
	  SELECT Movie.length FROM Movie
    WHERE Movie.name='Star Wars'
)

-- Напишете заявка, която извежда имената на продуцентите и имената на филмите за всички филми, 
-- които са продуцирани от продуценти с нетни активи по-големи от тези на ‘Merv Griffin’
SELECT Movie.title, MovieExec.name FROM MovieExec
JOIN Movie
ON Movie.producerc#=MovieExec.cert#
WHERE MovieExec.networth > (
	SELECT MovieExec.networth FROM MovieExec
	WHERE MovieExec.name='Merv Griffin'
)
