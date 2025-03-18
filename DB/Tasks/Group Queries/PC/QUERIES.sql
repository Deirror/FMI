USE PC

-- Напишете заявка, която извежда средната честота на персоналните компютри
SELECT AVG(speed) AS AvgSpeed FROM PC

-- Напишете заявка, която извежда средния размер на екраните на лаптопите за всеки производител
SELECT Product.maker, AVG(Laptop.screen) AS AvgScreen FROM Laptop
JOIN Product
ON Product.model=Laptop.model
GROUP BY(Product.maker)

-- Напишете заявка, която извежда средната честота на лаптопите с цена над 1000
SELECT AVG(Laptop.speed) AS AvgSpeed FROM Laptop
WHERE Laptop.price > 1000

-- Напишете заявка, която извежда средната цена на персоналните компютри, произведени от производител ‘A’
SELECT Product.maker, AVG(PC.price) AS AvgScreen FROM PC
JOIN Product
ON Product.model=PC.model
WHERE Product.maker='A'
GROUP BY(Product.maker)

-- Напишете заявка, която извежда средната цена на персоналните компютри и лаптопите за производител ‘B’
SELECT Combined.maker, AVG(price) AS average_price
FROM (
    SELECT maker, price FROM PC 
	JOIN Product
	ON Product.model=PC.model
	WHERE maker = 'B'
    UNION ALL
    SELECT maker, price FROM Laptop
	JOIN Product
	ON Product.model=Laptop.model
	WHERE maker = 'B'
) AS Combined
GROUP BY(Combined.maker)
-- или
SELECT (SUM(PC.price) + SUM(Laptop.price)) / COUNT(*) AS AvgPrice FROM Product
FULL JOIN PC ON Product.model=PC.model
FULL JOIN Lalptop ON Product.model=Lalptop.model
WHERE product.maker = 'B'

-- Напишете заявка, която извежда средната цена на персоналните компютри според различните им честоти
SELECT PC.speed, AVG(PC.price) AS AvgPrcie FROM PC
GROUP BY(PC.speed)

-- Напишете заявка, която извежда производителите, които са произвели поне 3 различни персонални компютъра (с различен код)
SELECT Product.maker, COUNT(PC.code) AS Number_Of_PC FROM Product
JOIN PC
ON PC.model=Product.model
GROUP BY Product.maker
HAVING COUNT(PC.code) >= 3

-- Напишете заявка, която извежда производителите с най-висока цена на персонален компютър
SELECT Product.maker, MAX(PC.price) AS price FROM Product
JOIN PC
ON PC.model=Product.model
WHERE PC.price=(SELECT MAX(PC.price) FROM PC)
GROUP BY Product.maker

-- Напишете заявка, която извежда средната цена на персоналните компютри за всяка честота по-голяма от 800
SELECT PC.speed, AVG(PC.price) AS AvgPrcie FROM PC
GROUP BY(PC.speed)
HAVING PC.speed>800

-- Напишете заявка, която извежда средния размер на диска на тези персонални компютри, 
-- произведени от производители, които произвеждат и принтери
-- Резултатът да се изведе за всеки отделен производител
SELECT Product.maker, AVG(PC.hd) AS AvgHDD FROM Product
JOIN PC
ON PC.model=Product.model
WHERE Product.maker IN (
	SELECT Product.maker FROM Product
	JOIN Printer
	ON Printer.model=Product.model
)
GROUP BY Product.maker
