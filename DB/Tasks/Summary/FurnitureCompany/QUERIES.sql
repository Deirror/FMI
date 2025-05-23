-- Като използвате диаграмата по-долу, създайте базата от данни FurnitureCompany и
-- дефинирайте схемата на всяка релация. Добавете подходящи ограничения (PK, FK и др.)

CREATE DATABASE FurnitureCompany;

CREATE TABLE Product (
	Product_ID INT PRIMARY KEY,
	Product_Description VARCHAR(70),
	Product_Finish VARCHAR(40) NOT NULL,
	Standard_Price INT NOT NULL,
	Product_Line_ID INT,
	CONSTRAINT FK_Finish_Check CHECK (
		Product_Finish IN (
			'череша',
			'естествен ясен',
			'бял ясен',
			'червен дъб',
			'естествен дъб',
			'орех'
		)
	)
);

CREATE TABLE Customer (
	Customer_ID INT IDENTITY(1,1) PRIMARY KEY,
	Customer_Name VARCHAR(40),
	Customer_Address VARCHAR(50) NOT NULL,
	Customer_City VARCHAR(30) NOT NULL,
	City_Code CHAR(4) NOT NULL
);

CREATE TABLE Order_t (
	Order_ID INT PRIMARY KEY,
	Order_Date DATETIME NOT NULL,
	Customer_ID INT NOT NULL,
	CONSTRAINT FK_Customer_ID FOREIGN KEY (Customer_ID) 
	REFERENCES Customer(Customer_ID)
);

CREATE TABLE Order_line (
	Order_ID INT,
	Product_ID INT NOT NULL,
	Ordered_Quantity INT,
	CONSTRAINT FK_Order_ID FOREIGN KEY (Order_ID) 
	REFERENCES Order_t(Order_ID),
	CONSTRAINT FK_Product_ID FOREIGN KEY (Product_ID) 
	REFERENCES Product(Product_ID),
	CONSTRAINT PK_Order_Customer_ID PRIMARY KEY (Order_ID, Product_ID)
);

-- Copy-pasted.
insert into CUSTOMER values
('Иван Петров', 'ул. Лавеле 8', 'София', '1000'),
('Камелия Янева', 'ул. Иван Шишман 3', 'Бургас', '8000'),
('Васил Димитров', 'ул. Абаджийска 87', 'Пловдив', '4000'),
('Ани Милева', 'бул. Владислав Варненчик 56', 'Варна','9000');
insert into PRODUCT values
(1000, 'офис бюро', 'череша', 195, 10),
(1001, 'директорско бюро', 'червен дъб', 250, 10),
(2000, 'офис стол', 'череша', 75, 20),
(2001, 'директорски стол', 'естествен дъб', 129, 20),
(3000, 'етажерка за книги', 'естествен ясен', 85, 30),
(4000, 'настолна лампа', 'естествен ясен', 35, 40);
insert into ORDER_T values
(100, '2013-01-05', 1),
(101, '2013-12-07', 2),
(102, '2014-10-03', 3),
(103, '2014-10-08', 2),
(104, '2015-10-05', 1),
(105, '2015-10-05', 4),
(106, '2015-10-06', 2),
(107, '2016-01-06', 1);
insert into ORDER_LINE values
(100, 4000, 1),
(101, 1000, 2),
(101, 2000, 2),
(102, 3000, 1),
(102, 2000, 1),
(106, 4000, 1),
(103, 4000, 1),
(104, 4000, 1),
(105, 4000, 1),
(107, 4000, 1);

-- Напишете заявка, която извежда id и описание на продукт, както и колко пъти е бил поръчан,
-- само за тези продукти, които са били поръчвани

SELECT Product.Product_ID, Product.Product_Description, COUNT(Order_line.Product_ID) FROM Product
JOIN Order_line
ON Order_line.Product_ID=Product.Product_ID
GROUP BY Product.Product_ID, Product.Product_Description
HAVING COUNT(Order_line.Product_ID) > 0;

-- Напишете заявка, която извежда id и описание на продукт, както и поръчано количество, за всички продукти

SELECT Product.Product_ID, Product.Product_Description, COUNT(Order_line.Product_ID) FROM Product
LEFT JOIN Order_line
ON Order_line.Product_ID=Product.Product_ID
GROUP BY Product.Product_ID, Product.Product_Description

-- Напишете заявка, която извежда име на клиента и обща стойност на направените от него
-- поръчки, само за клиентите с поръчки

