USE PC

-- Напишете заявка, която извежда производител, модел и тип на продукт за тези производители, 
-- за които съответният продукт не се продава (няма го в таблиците PC, Laptop или Printer)
SELECT DISTINCT Product.maker, Product.model, Product.type FROM Product
LEFT JOIN PC
ON PC.model=Product.model
LEFT JOIN Laptop
ON Laptop.model=Product.model
LEFT JOIN Printer
ON Printer.model=Product.model
WHERE PC.model IS NULL AND Laptop.model IS NULL AND Printer.model IS NULL

-- Намерете всички производители, които правят както лаптопи, така и принтери
SELECT DISTINCT P1.maker FROM Product P1
JOIN Product P2
ON P1.maker=P2.maker
WHERE (P1.type='Laptop' AND P2.type='Printer') OR (P1.type='Printer' AND P2.type='Laptop')

-- Намерете размерите на тези твърди дискове, които се появяват в два или повече модела лаптопи
SELECT DISTINCT L1.hd FROM Laptop L1
WHERE ( SELECT COUNT(L2.hd) FROM Laptop L2
WHERE L2.hd=L1.hd ) >= 2

-- Намерете всички модели персонални компютри, които нямат регистриран производител
SELECT * FROM PC
LEFT JOIN Product
ON PC.model=Product.model
WHERE Product.maker IS NULL
