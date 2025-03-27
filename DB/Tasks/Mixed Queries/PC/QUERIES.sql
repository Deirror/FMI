USE PC

-- Напишете заявка, която извежда всички модели лаптопи, за които се
-- предлагат както разновидности с 15" екран, така и с 11" екран
SELECT Laptop.model, Laptop.code, Laptop.screen FROM Laptop
WHERE Laptop.screen=11 OR Laptop.screen=15

-- Да се изведат различните модели компютри, чиято цена е по-ниска от найевтиния лаптоп, 
-- произвеждан от същия производител
SELECT DISTINCT PC.model FROM PC
JOIN Product P1
ON P1.model=PC.model
WHERE PC.price<=(
	SELECT MIN(Laptop.price) FROM Laptop
	JOIN Product P2
	ON P2.model=Laptop.model
	WHERE P1.maker=P2.maker
)

-- Един модел компютри може да се предлага в няколко разновидности с
-- различна цена. Да се изведат тези модели компютри, чиято средна цена (на
-- различните му разновидности) е по-ниска от най-евтиния лаптоп, произвеждан
-- от същия производител
SELECT PC.model, AVG(PC.price) AS avg_price FROM PC
JOIN Product P1
ON P1.model=PC.model
GROUP BY PC.model, P1.maker
HAVING AVG(PC.price) < (
SELECT MIN(Laptop.price) FROM Laptop
	JOIN Product P2
	ON P2.model=Laptop.model
	WHERE P1.maker=P2.maker
	GROUP BY P2.maker
)

-- Напишете заявка, която извежда за всеки компютър код на продукта,
-- производител и брой компютри, които имат цена, по-голяма или равна на неговата
SELECT 
    PC.model, 
    Product.maker, 
    (SELECT COUNT(*) 
     FROM PC AS PC2 
     WHERE PC2.price >= PC.price) AS num_higher_or_equal
FROM PC
JOIN Product 
    ON PC.model = Product.model
