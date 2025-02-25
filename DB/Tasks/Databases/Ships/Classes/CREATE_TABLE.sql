USE Ships

CREATE TABLE Classes (
	class VARCHAR(50) PRIMARY KEY,
	type CHAR(2) NOT NULL,
	country VARCHAR(60) NOT NULL,
	numguns INT,
	bore REAL,
	displacement INT
)