USE PC

-- Да се напише заявка, която извежда производителите както на принтери, така и на лаптопи
-- Забележка: Предложете 2 варианта за решаване на задачата - с подзаявка и със съединение

SELECT Product.maker FROM Product
JOIN Printer
ON Printer.model=Product.maker
JOIN Laptop
ON Laptop.model=Product.maker;

SELECT Product.maker FROM Product
WHERE Product.model IN (
    SELECT Laptop.model FROM Laptop
) AND (
    SELECT Printer.model FROM Printer
)

-- Намалете с 5% цената на онези персонални компютри, които имат производители,
-- такива че средната цена на продаваните от тях принтери е над 800

UPDATE PC
SET price = price * 0.95
WHERE model IN (
    SELECT model FROM Product
    WHERE maker IN (
        SELECT maker
        FROM Product
        JOIN Printer ON Product.model = Printer.model
        GROUP BY maker
        HAVING AVG(Printer.price) > 800
    )
    AND model IN (SELECT model FROM PC)
)

-- Намерете за всеки размер на твърд диск на персонален компютър между 10 и 30 GB, най-ниската цена за съответния размер

SELECT PC.hd, MIN(PC.price) FROM PC
WHERE PC.hd >= 10 AND PC.hd <= 30
GROUP BY PC.hd
