CREATE DATABASE FurnitureCompany;

CREATE TABLE Product (
	Product_ID INTEGER PRIMARY KEY,
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
	
);

CREATE TABLE Order_t (
	
);

CREATE TABLE Order_Line (
	
);
