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
