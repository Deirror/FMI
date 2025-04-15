-- а) Дефинирайте следните релации:
-- - Product (maker, model, type), където:
--   - модел е низ от точно 4 символа,
--   - производител е низ от точно 1 символ,
--   - тип е низ до 7 символа;
CREATE TABLE Product(
    maker CHAR(4),
    model CHAR(1),
    type VARCHAR(7)
);

-- - Printer (code, model, price), където:
--   - код е цяло число,
--   - модел е низ от точно 4 символа,
--   - цена с точност до два знака след десетичната запетая;
CREATE TABLE Printer(
    code INT,
    model CHAR(4),
    price DECIMAL(10, 2)
);

-- б) Добавете кортежи с примерни данни към новосъздадените релации
INSERT INTO Product
VALUES('BAGG', 'A', 'Printer'),
('ACDC', 'D', 'PC')

INSERT INTO Printer
VALUES(121, 'A', 1212,12)


-- в) Добавете към релацията Printer атрибути:
--   - type - низ до 6 символа
--   - color - низ от точно 1 символ, стойност по подразбиране 'n'
ALTER TABLE Printer ADD type VARCHAR(6), COLOR BIT

-- г) Напишете заявка, която премахва атрибута price от релацията Printer
ALTER TABLE Printer DROP COLUMN price

-- д) Изтрийте релациите, които сте създали в Задача 1
DROP TABLE Printer, Product
