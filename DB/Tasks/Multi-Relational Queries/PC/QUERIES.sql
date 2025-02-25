USE PC

-- Напишете заявка, която извежда производителя и честотата на лаптопите с размер на диска поне 9 GB
SELECT Product.maker, speed FROM Laptop
JOIN Product
ON Product.model=Laptop.model
WHERE hd > 8

-- Напишете заявка, която извежда модел и цена на продуктите, произведени от производител с име B
SELECT DISTINCT Product.model, COALESCE(Laptop.price, PC.price, Printer.price) AS price FROM Product
LEFT JOIN Laptop
ON Product.model=Laptop.model
LEFT JOIN PC
ON Product.model=PC.model
LEFT JOIN Printer
ON Product.model=Printer.model
WHERE Product.maker='B'

-- Напишете заявка, която извежда производителите, които произвеждат лаптопи, но не произвеждат персонални компютри
SELECT DISTINCT Product.maker
FROM Product
JOIN Laptop ON Product.model = Laptop.model
WHERE Product.maker NOT IN (
    SELECT DISTINCT Product.maker
    FROM Product
    JOIN PC ON Product.model = PC.model
)

-- Напишете заявка, която извежда размерите на тези дискове, които се предлагат
-- в поне два различни персонални компютъра (два компютъра с различен код)
SELECT hd
FROM (
    SELECT hd, code
    FROM PC
    GROUP BY hd, code
) AS subquery
GROUP BY hd
HAVING COUNT(*) >= 2

-- Напишете заявка, която извежда двойките модели на персонални компютри,
-- които имат еднаква честота и памет. Двойките трябва да се показват само по
-- веднъж, например само (i, j), но не и (j, i)
SELECT A.model AS model1, B.model AS model2
FROM PC A
JOIN PC B ON A.speed = B.speed 
AND A.ram = B.ram
AND A.code < B.code

-- Напишете заявка, която извежда производителите на поне два различни персонални компютъра с честота поне 400
SELECT Product.maker
FROM Product
JOIN PC ON Product.model = PC.model
WHERE PC.speed >= 400
GROUP BY Product.maker
HAVING COUNT(DISTINCT PC.code) >= 2;
