USE Movies

-- Напишете заявка, която извежда заглавие и година на всички филми, които са
-- по-дълги от 120 минути и са снимани преди 2000 г. Ако дължината на филма е
-- неизвестна, заглавието и годината на този филм също да се изведат
SELECT Movie.title. Movie.year, Movie.length FROM Movie
WHERE (Movie.length > 120 OR Movie.length IS NULL) and Movie.year < 2000

-- Напишете заявка, която извежда име и пол на всички актьори (мъже и жени),
-- чието име започва с 'J' и са родени след 1948 година. Резултатът да бъде
-- подреден по име в намаляващ ред
SELECT MovieStar.name, MovieStar.gender FROM MovieStar
WHERE MovieStar.name LIKE 'J%' AND MovieStar.birthday > 1948

-- Напишете заявка, която извежда име на студио и брой на актьорите,
-- участвали във филми, които са създадени от това студио
SELECT Studio.name, COUNT(StarsIn.starname) FROM Studio
...(I will be back in 37 mins)
