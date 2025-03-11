USE Movies

-- Напишете заявка, която извежда името на продуцента и имената на филмите, продуцирани от продуцента на филма 'Star Wars'
SELECT Movie.title, MovieExec.name FROM Movie
JOIN MovieExec
ON MovieExec.cert#=Movie.producerc#
WHERE MovieExec.name=(
SELECT DISTINCT MovieExec.name FROM MovieExec 
JOIN Movie
ON Movie.producerc#=MovieExec.cert#
WHERE Movie.title='Star Wars'
)

-- Напишете заявка, която извежда имената на продуцентите на филмите, в които е участвал ‘Harrison Ford’
SELECT DISTINCT MovieExec.name FROM Movie
JOIN MovieExec
ON Movie.producerc#=MovieExec.cert#
JOIN StarsIn
ON StarsIn.movietitle=Movie.title
AND StarsIn.movieyear=Movie.year
JOIN MovieStar
ON MovieStar.name=StarsIn.starname
WHERE MovieStar.name='Harrison Ford'

-- Напишете заявка, която извежда името на студиото и имената на актьорите, 
-- участвали във филми, произведени от това студио, подредени по име на студио
SELECT DISTINCT Studio.name, StarsIn.starname FROM Movie
JOIN Studio
ON Studio.name=Movie.studioname
JOIN StarsIn
ON StarsIn.movietitle=Movie.title
AND StarsIn.movieyear=Movie.year
ORDER BY Studio.name

-- Напишете заявка, която извежда имената на актьорите, участвали във филми на продуценти с най-големи нетни активи
SELECT StarsIn.starname, MovieExec.networth, StarsIn.movietitle FROM Movie
JOIN MovieExec
ON MovieExec.cert#=Movie.producerc#
JOIN StarsIn
ON StarsIn.movietitle=Movie.title
AND StarsIn.movieyear=Movie.year
WHERE MovieExec.networth=(
SELECT MAX(MovieExec.networth) FROM MovieExec
)

-- Напишете заявка, която извежда имената на актьорите, които не са участвали в нито един филм
SELECT MovieStar.name, StarsIn.movietitle FROM StarsIn 
RIGHT JOIN MovieStar
ON MovieStar.name=StarsIn.starname
WHERE MovieStar.name NOT IN (
SELECT StarsIn.starname FROM StarsIn 
)
