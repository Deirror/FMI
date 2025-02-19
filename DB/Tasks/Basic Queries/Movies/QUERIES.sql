USE Movies

--Напишете заявка, която извежда адреса на студио ‘Disney’
SELECT address FROM Studio WHERE name='Disney'

--Напишете заявка, която извежда рождената дата на актьора Jack Nicholson
SELECT birthdate FROM MovieStar WHERE name='Jack Nicholson'

--Напишете заявка, която извежда имената на актьорите, които са участвали във филм от 1980 или във филм, в чието заглавие има думата ‘Knight’
SELECT starname FROM StarsIn WHERE movieyear=1980 OR movietitle LIKE '%Knights%'

--Напишете заявка, която извежда имената на продуцентите с нетни активи над 10 000 000 долара
SELECT name FROM MovieExec WHERE networth > 1000

--Напишете заявка, която извежда имената на актьорите, които са мъже или живеят на Prefect Rd
SELECT name FROM MovieStar WHERE gender='M' OR address='Prefect Rd'
