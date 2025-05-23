USE Ships

-- Съставете изгледи, съдържащи имената на битките, които са по-мащабни от битката при Guadalcanal. Под по-мащабна битка се разбира:
-- a) битка с повече участващи кораби;
-- b) битка с повече участващи страни.
-- Като използвате изгледите, напишете заявки, които извеждат съответните битки

CREATE VIEW V_Battles_A AS
SELECT O1.battle
FROM Outcomes O1
GROUP BY O1.battle
HAVING COUNT(O1.ship) > (
  SELECT COUNT(O2.ship)
  FROM Outcomes O2
  WHERE O2.battle = 'Guadalcanal'
)

CREATE VIEW V_Battles_B AS
SELECT O1.battle
FROM Outcomes O1
JOIN Ships S ON O1.ship = S.name
JOIN Classes C ON S.class = C.class
GROUP BY O1.battle
HAVING COUNT(DISTINCT C.country) > (
  SELECT COUNT(DISTINCT C2.country)
  FROM Outcomes O2
  JOIN Ships S2 ON O2.ship = S2.name
  JOIN Classes C2 ON S2.class = C2.class
  WHERE O2.battle = 'Guadalcanal'
)

-- Изтрийте от таблицата Outcomes всички битки, в които е участвал един единствен кораб

DELETE FROM Outcomes
WHERE battle IN (
  SELECT battle
  FROM Outcomes
  GROUP BY battle
  HAVING COUNT(ship) = 1
)

-- Изтрийте от таблицата Outcomes всички записи, в които участва кораб, потапян поне два
-- пъти и резултатът от съответната битка е 'sunk'
-- Забележка: Преди това може да вмъкнете следните кортежи, за да проверите по-лесно как работи написаната заявка
  
INSERT INTO Outcomes VALUES ('Missouri','Surigao Strait', 'sunk'),
('Missouri','North Cape', 'sunk'),
('Missouri','North Atlantic', 'ok')

DELETE FROM Outcomes
WHERE result='sunk' AND ship IN (
  SELECT ship FROM Outcomes
  WHERE result='sunk'
  GROUP BY ship
  HAVING COUNT(result) > 1
)

-- Изведете всички битки, в които са участвали същите страни, като страните в битката при Guadalcanal

CREATE VIEW V_Battles_Contries (battle, country) AS
SELECT Outcomes.battle, Classes.country FROM Outcomes
JOIN Ships
ON Ships.name=Outcomes.ship
JOIN Classes
ON Classes.class=Ships.class

SELECT DISTINCT battle
FROM V_Battles_Countries AS B1
WHERE NOT EXISTS (
    SELECT country
    FROM V_Battles_Countries
    WHERE battle = B1.battle
    EXCEPT
    SELECT country
    FROM V_Battles_Countries
    WHERE battle = 'Guadalcanal'
)
AND NOT EXISTS (
    SELECT country
    FROM V_Battles_Countries
    WHERE battle = 'Guadalcanal'
    EXCEPT
    SELECT country
    FROM V_Battles_Countries
    WHERE battle = B1.battle
)

-- Намерете всяка страна в колко битки е участвала
-- Забележка: Ако страната не е участвала в нито една битка (защото (а) няма кораби или (б) има
-- кораби, но те не са участвали в битка), то трябва да се покаже в резултата с брой кораби 0

SELECT C.country, COUNT(O1.battle) AS num_battles
FROM Classes C
LEFT JOIN Ships S ON C.class = S.class
LEFT JOIN Outcomes O1 ON O1.ship = S.name
GROUP BY C.country
