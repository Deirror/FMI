USE PC

-- Напишете заявка, която извежда производителя и честотата на лаптопите с размер на диска поне 9 GB
SELECT Product.maker, speed FROM Laptop
JOIN Product
ON Product.model=Laptop.model
WHERE hd > 8

-- Напишете заявка, която извежда модел и цена на продуктите, произведени от производител с име B
