USE PC

CREATE TABLE Product (
	model VARCHAR(50) PRIMARY KEY,
	maker VARCHAR(50) NOT NULL,
	type VARCHAR(10) CHECK(type IN('PC','Laptop','Printer')) NOT NULL
)