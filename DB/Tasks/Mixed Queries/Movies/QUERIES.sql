USE Movies

-- Напишете заявка, която извежда заглавие и година на всички филми, които са
-- по-дълги от 120 минути и са снимани преди 2000 г. Ако дължината на филма е
-- неизвестна, заглавието и годината на този филм също да се изведат
SELECT Movie.title, Movie.year, Movie.length FROM Movie
WHERE (Movie.length > 120 OR Movie.length IS NULL) and Movie.year < 2000

-- Напишете заявка, която извежда име и пол на всички актьори (мъже и жени),
-- чието име започва с 'J' и са родени след 1948 година. Резултатът да бъде
-- подреден по име в намаляващ ред
SELECT MovieStar.name, MovieStar.gender FROM MovieStar
WHERE MovieStar.name LIKE 'J%' AND MovieStar.birthday > 1948

-- Напишете заявка, която извежда име на студио и брой на актьорите,
-- участвали във филми, които са създадени от това студио
SELECT Movie.studioname, COUNT(DISTINCT StarsIn.starname) AS num_actors FROM Movie
JOIN StarsIn
ON StarsIn.movietitle=Movie.title
AND StarsIn.movieyear=Movie.year
GROUP BY(Movie.studioname)

-- Напишете заявка, която за всеки актьор извежда име на актьора и броя на
-- филмите, в които актьорът е участвал
SELECT MovieStar.name, COUNT(StarsIn.movietitle) as num_movies FROM StarsIn
RIGHT JOIN MovieStar
ON MovieStar.name=StarsIn.starname
GROUP BY(MovieStar.name)

-- Напишете заявка, която за всяко студио извежда име на студиото и заглавие
-- на филма, излязъл последно на екран за това студио
SELECT DISTINCT M1.studioname, M1.title, M1.year FROM Movie M1
WHERE M1.year=(
SELECT MAX(M2.year) FROM Movie M2
WHERE M2.studioname=M1.studioname
)

-- Напишете заявка, която извежда името на най-младия актьор (мъж)
SELECT MovieStar.name FROM MovieStar
WHERE MovieStar.birthdate=(
SELECT TOP 1 MovieStar.birthdate FROM MovieStar
WHERE MovieStar.gender='M'
ORDER BY MovieStar.birthdate DESC
)

-- Напишете заявка, която извежда име на актьор и име на студио за тези
-- актьори, участвали в най-много филми на това студио
WITH StarMovieCounts AS (
    SELECT 
        Movie.studioname, 
        StarsIn.starname, 
        COUNT(*) AS num_movies
    FROM Movie
    JOIN StarsIn
        ON StarsIn.movietitle = Movie.title
        AND StarsIn.movieyear = Movie.year
    GROUP BY Movie.studioname, StarsIn.starname
)
SELECT sm1.studioname, sm1.starname, sm1.num_movies
FROM StarMovieCounts sm1
WHERE sm1.num_movies = (
    SELECT MAX(sm2.num_movies)
    FROM StarMovieCounts sm2
    WHERE sm2.studioname = sm1.studioname
);

-- Напишете заявка, която извежда заглавие и година на филма, и брой на
-- актьорите, участвали в този филм за тези филми с повече от двама актьори
WITH RES AS (SELECT StarsIn.movietitle, StarsIn.movieyear, COUNT(*) as num_actors FROM StarsIn
GROUP BY StarsIn.movietitle, StarsIn.movieyear) SELECT * FROM RES R1
WHERE R1.num_actors > 2
