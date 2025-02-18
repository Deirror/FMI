USE Movies

------- Insert Studio ------------
INSERT INTO STUDIO
  VALUES ('Disney','500 S. Buena Vista Street',1);

INSERT INTO STUDIO
  VALUES ('USA Entertainm.','', 2);

INSERT INTO STUDIO
  VALUES ('Fox','10201 Pico Boulevard', 3);

INSERT INTO STUDIO
  VALUES ('Paramount','5555 Melrose Ave', 4);

INSERT INTO STUDIO
  VALUES ('MGM','MGM Boulevard', 5);
  
------- Insert MovieExec ------------  
INSERT INTO MOVIEEXEC (NAME, ADDRESS, CERT#, NETWORTH)
  VALUES ('George Lucas', 'Oak Rd.', 555, 2000);

INSERT INTO MOVIEEXEC (NAME, ADDRESS, CERT#, NETWORTH)
  VALUES ('Ted Turner', 'Turner Av.', 333, 12500);

INSERT INTO MOVIEEXEC (NAME, ADDRESS, CERT#, NETWORTH)
  VALUES ('Stephen Spielberg', '123 ET road', 222, 10000);

INSERT INTO MOVIEEXEC (NAME, ADDRESS, CERT#, NETWORTH)
  VALUES ('Merv Griffin', 'Riot Rd.', 199, 11200);

INSERT INTO MOVIEEXEC (NAME, ADDRESS, CERT#, NETWORTH)
  VALUES ('Calvin Coolidge', 'Fast Lane', 123, 20000);

------- Insert Movie ------------
INSERT INTO MOVIE
  VALUES ('Pretty Woman', 1990, 119, 1, 'Disney', 199);

INSERT INTO MOVIE
  VALUES ('The Man Who Wasn''t There', 2001, 116, 0, 'USA Entertainm.',
    555);

INSERT INTO MOVIE
  VALUES ('Logan''s run', 1976, NULL, 1, 'Fox', 333);

INSERT INTO MOVIE
  VALUES ('Star Wars', 1977, 124, 1, 'Fox', 555);

INSERT INTO MOVIE
  VALUES ('Empire Strikes Back', 1980, 111, 1, 'Fox', 555);

INSERT INTO MOVIE
  VALUES ('Star Trek', 1979, 132, 1, 'Paramount', 222);

INSERT INTO MOVIE
  VALUES ('Star Trek: Nemesis', 2002, 116, 1, 'Paramount', 123);

INSERT INTO MOVIE
  VALUES ('Terms of Endearment', 1983, 132, 1, 'MGM', 123);

INSERT INTO MOVIE
  VALUES ('The Usual Suspects', 1995, 106, 1, 'MGM', 199);

INSERT INTO MOVIE
  VALUES ('Gone With the Wind', 1938, 238, 1, 'MGM', 123);

------- Insert MovieStar ------------

INSERT INTO MOVIESTAR
  VALUES ('Jane Fonda', 'Turner Av.', 'F', '1977-07-07');

INSERT INTO MOVIESTAR
  VALUES ('Alec Baldwin', 'Baldwin Av.', 'M', '1977-07-06');

INSERT INTO MOVIESTAR
  VALUES ('Kim Basinger', 'Baldwin Av.', 'F', '1979-07-05');

INSERT INTO MOVIESTAR
  VALUES ('Harrison Ford', 'Prefect Rd.', 'M', '1955-05-05');

INSERT INTO MOVIESTAR
  VALUES ('Debra Winger', 'A way', 'F', '1978-06-05');

INSERT INTO MOVIESTAR
  VALUES ('Jack Nicholson', 'X path', 'M', '1949-05-05');
  
INSERT INTO MOVIESTAR
  VALUES ('Sandra Bullock', 'X path', 'F', '1948-12-05');

------- Insert StarsIn ------------
INSERT INTO STARSIN
  VALUES ('Star Wars', 1977, 'Kim Basinger');

INSERT INTO STARSIN
  VALUES ('Star Wars', 1977, 'Alec Baldwin');

INSERT INTO STARSIN
  VALUES ('Star Wars', 1977, 'Harrison Ford');

INSERT INTO STARSIN
  VALUES ('Empire Strikes Back', 1980, 'Harrison Ford');

INSERT INTO STARSIN
  VALUES ('The Usual Suspects', 1995, 'Jack Nicholson');

INSERT INTO STARSIN
  VALUES ('Terms of Endearment', 1983, 'Jane Fonda');

INSERT INTO STARSIN
  VALUES ('Terms of Endearment', 1983, 'Jack Nicholson');

INSERT INTO STARSIN
  VALUES ('The Usual Suspects', 1995, 'Sandra Bullock')