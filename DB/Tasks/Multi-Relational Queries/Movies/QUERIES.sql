USE Movies

--Напишете заявка, която извежда имената на актьорите мъже, участвали във филма The Usual Suspects.
SELECT MovieStar.name FROM MovieStar 
JOIN StarsIn
ON StarsIn.starname=MovieStar.name
WHERE MovieStar.gender='M' AND StarsIn.movietitle='The Usual Suspects'

-- 
