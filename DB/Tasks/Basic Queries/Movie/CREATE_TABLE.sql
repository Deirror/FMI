USE WEEK_01

CREATE TABLE Movie (
	title VARCHAR(50),
	year INT,
	length INT,
	incolor BIT,
	studioname VARCHAR(50) FOREIGN KEY REFERENCES Studio(name),
	producerc# INT FOREIGN KEY REFERENCES MovieExec(cert#),
	PRIMARY KEY(title, year)
)
