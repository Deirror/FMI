USE Movies

-- Напишете заявка, която извежда имената на актьорите мъже, участвали във филма The Usual Suspects
SELECT MovieStar.name FROM MovieStar 
JOIN StarsIn
ON StarsIn.starname=MovieStar.name
WHERE MovieStar.gender='M' AND StarsIn.movietitle='The Usual Suspects'

-- Напишете заявка, която извежда имената на актьорите, участвали във филми от 1995, продуцирани от студио MGM
SELECT StarsIn.starname FROM StarsIn 
JOIN Movie
ON Movie.title = StarsIn.movietitle
AND Movie.year = StarsIn.movieyear
WHERE StarsIn.movieyear=1995 AND Movie.studioname='MGM'

-- Напишете заявка, която извежда имената на продуцентите, които са продуцирали филми на студио MGM
SELECT DISTINCT MovieExec.name FROM MovieExec
JOIN Movie
ON MovieExec.cert#=Movie.producerc#
WHERE Movie.studioname='MGM'

-- Напишете заявка, която извежда имената на филми с дължина, по-голяма от дължината на филма Star Wars
SELECT title FROM Movie WHERE length > (SELECT length FROM Movie WHERE title='Star Wars')

-- Напишете заявка, която извежда имената на продуцентите с нетни активи поголеми от тези на Stephen Spielberg
SELECT name FROM MovieExec WHERE networth > (SELECT networth FROM MovieExec WHERE name='Stephen Spielberg')
