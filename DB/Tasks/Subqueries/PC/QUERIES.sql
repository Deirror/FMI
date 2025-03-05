USE PC

-- Напишете заявка, която извежда производителите на персонални компютри с честота над 500
SELECT DISTINCT Product.maker FROM Product
JOIN PC
ON PC.model=Product.model
WHERE PC.speed > 500

-- Напишете заявка, която извежда код, модел и цена на принтерите с найвисока цена
SELECT Printer.code, Printer.model, Printer.price FROM Printer
WHERE Printer.price=(
	SELECT MAX(Printer.price) FROM Printer
)

-- Напишете заявка, която извежда лаптопите, чиято честота е по-ниска от честотата на всички персонални компютри
SELECT * FROM Laptop
WHERE Laptop.speed < ALL(
    SELECT PC.speed FROM PC
)

-- Напишете заявка, която извежда модела и цената на продукта (PC, лаптоп или принтер) с най-висока цена
SELECT TOP 1 Product.model, MAX(COALESCE(PC.price, Laptop.price, Printer.price)) AS price FROM Product 
LEFT JOIN PC
ON PC.model=Product.model
LEFT JOIN Laptop
ON Laptop.model=Product.model
LEFT JOIN Printer
ON Printer.model=Product.model
GROUP BY Product.model
ORDER BY price DESC

-- Напишете заявка, която извежда производителя на цветния принтер с най-ниска цена
SELECT TOP 1 Product.maker FROM Printer
JOIN Product
ON Product.model=Printer.model
WHERE Printer.color='y'
ORDER BY Printer.price

-- Напишете заявка, която извежда производителите на тези персонални 
-- компютри с най-малко RAM памет, които имат най-бързи процесори
SELECT DISTINCT Product.maker
FROM Product
JOIN PC ON Product.model=PC.model
WHERE PC.ram=(SELECT MIN(PC.ram) FROM PC)
AND PC.speed=(SELECT MAX(PC.speed) FROM PC WHERE PC.ram = (SELECT MIN(PC.ram) FROM PC))
