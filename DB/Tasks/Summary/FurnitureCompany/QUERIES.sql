CREATE DATABASE FurnitureCompany;

CREATE TABLE Product (
	Product_ID INT PRIMARY KEY,
	Product_Description VARCHAR(70),
	Product_Finish VARCHAR(40),
	Standart_Price INTEGER,
	Product_Line_ID INT,
	CONSTRAINT VALID_FINISH_CHECK CHECK (
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
	Customer_Address VARCHAR(50),
	Customer_City VARCHAR(30),
	City_Code CHAR(4)
);

CREATE TABLE Order_t (
	Order_ID INT PRIMARY KEY,
	...
);

CREATE TABLE Order_line (
	
);
