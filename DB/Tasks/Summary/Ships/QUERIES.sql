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
);
