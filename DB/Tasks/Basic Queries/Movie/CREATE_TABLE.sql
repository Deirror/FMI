USE WEEK_01

CREATE TABLE Movie (
	title TEXT,
	year INT,
	length INT,
	incolor BIT,
	studioname FOREIGN KEY REFERENCES Studio(name),
	producerc# FOREIGN KEY REFERENCES MovieExec(cert#)
)
