USE Ships

CREATE TABLE Ships (
	name VARCHAR(50) PRIMARY KEY,
	class VARCHAR(50) FOREIGN KEY REFERENCES Classes(class) NOT NULL,
	launched INT
)