USE PC

CREATE TABLE Printer (
	code INT PRIMARY KEY,
	model VARCHAR(50) FOREIGN KEY REFERENCES Product(model) NOT NULL,
	color CHAR(1) NOT NULL,
	type VARCHAR(7) CHECK(type IN('Laser', 'Jet', 'Matrix')) NOT NULL,
	price FLOAT NOT NULL
)