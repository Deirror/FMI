USE Movies

CREATE TABLE StarsIn (
    movietitle VARCHAR(50),
    movieyear INT,
    starname VARCHAR(50),
    PRIMARY KEY (movietitle, movieyear, starname),
    FOREIGN KEY (movietitle, movieyear) REFERENCES Movie(title, year),
    FOREIGN KEY (starname) REFERENCES MovieStar(name)
);
