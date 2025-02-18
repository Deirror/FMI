USE Ships

CREATE TABLE Outcomes (
	ship VARCHAR(50) FOREIGN KEY REFERENCES Ships(name) NOT NULL,
	battle VARCHAR(50) FOREIGN KEY REFERENCES Battles(name) NOT NULL,
	result VARCHAR(7) CHECK(result IN ('ok', 'sunk', 'damaged')) NOT NULL
)