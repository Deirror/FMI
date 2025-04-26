USE Flights

CREATE TABLE Airline (
	code VARCHAR(10) PRIMARY KEY,
	name VARCHAR(50) NOT NULL UNIQUE,
	country VARCHAR(50) NOT NULL
);

CREATE TABLE Airport (
	code VARCHAR(10) PRIMARY KEY,
	name VARCHAR(50) NOT NULL,
	country VARCHAR(50) NOT NULL,
	town VARCHAR(50) NOT NULL,
	UNIQUE(name, country)
);

CREATE TABLE Airplane (
	code VARCHAR(10) PRIMARY KEY,
	type VARCHAR(20) NOT NULL,
	seats_count INT CHECK(seats_count > 0) NOT NULL,
	production_year INT NOT NULL
);

CREATE TABLE Flight (
	number INT PRIMARY KEY,
	airline_code VARCHAR(10) FOREIGN KEY REFERENCES Airline(code),
	airport_departure_code VARCHAR(10) FOREIGN KEY REFERENCES Airport(code),
	airport_arrive_code VARCHAR(10) FOREIGN KEY REFERENCES Airport(code),
	date_time DATETIME NOT NULL,
	duration INT NOT NULL,
	airplane_code VARCHAR(10) FOREIGN KEY REFERENCES Airplane(code)
);

CREATE TABLE Customer (
	id INT PRIMARY KEY,
	first_name VARCHAR(50) NOT NULL,
	last_name VARCHAR(50) NOT NULL,
	e_mail VARCHAR(50) NOT NULL CHECK(e_mail LIKE '______%@%._%')
);

CREATE TABLE Agency (
	name VARCHAR(50) PRIMARY KEY,
	country VARCHAR(50) NOT NULL,
	town VARCHAR(50) NOT NULL,
	phone_number VARCHAR(30) NOT NULL
);

CREATE TABLE Booking (
	code VARCHAR(10) PRIMARY KEY,
	agency_name VARCHAR(50) FOREIGN KEY REFERENCES Agency(name),
	airline_code VARCHAR(10) FOREIGN KEY REFERENCES Airline(code),
	flight_number INT FOREIGN KEY REFERENCES Flight(number),
	customer_id INT FOREIGN KEY REFERENCES Customer(id),
	booking_date DATE DEFAULT GETDATE(),
	flight_date DATE NOT NULL,
	price DECIMAL(6, 2),
	status BIT,
	CHECK (booking_date<=flight_date)
);
