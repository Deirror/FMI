USE Ships

----- Classes ----- 
INSERT INTO Classes
  VALUES ('Bismarck', 'bb', 'Germany', 8, 15, 42000);

INSERT INTO Classes
  VALUES ('Iowa', 'bb', 'USA', 9, 16, 46000);

INSERT INTO Classes
  VALUES ('Kongo', 'bc', 'Japan', 8, 14, 32000);

INSERT INTO Classes
  VALUES ('North Carolina', 'bb', 'USA', 12, 16, 37000);

INSERT INTO Classes
  VALUES ('Renown', 'bc', 'Gt.Britain', 6, 15, 32000);

INSERT INTO Classes
  VALUES ('Revenge', 'bb', 'Gt.Britain', 8, 15, 29000);

INSERT INTO Classes
  VALUES ('Tennessee', 'bb', 'USA', 12, 14, 32000);

INSERT INTO Classes
  VALUES ('Yamato', 'bb', 'Japan', 9, 18, 65000);

----- Battles ----- 
INSERT INTO Battles
  VALUES ('Guadalcanal', '1942-11-15');

INSERT INTO Battles
  VALUES ('North Atlantic', '1941-05-25');

INSERT INTO Battles
  VALUES ('North Cape', '1943-12-26');

INSERT INTO Battles
  VALUES ('Surigao Strait', '1944-10-25');

----- Ships ----- 
INSERT INTO Ships
  VALUES ('California', 'Tennessee', 1921);

INSERT INTO Ships
  VALUES ('Haruna', 'Kongo', 1916);

INSERT INTO Ships
  VALUES ('Hiei', 'Kongo', 1914);

INSERT INTO Ships
  VALUES ('Iowa', 'Iowa', 1943);

INSERT INTO Ships
  VALUES ('Kirishima', 'Kongo', 1915);

INSERT INTO Ships
  VALUES ('Kongo', 'Kongo', 1913);

INSERT INTO Ships
  VALUES ('Missouri', 'Iowa', 1944);

INSERT INTO Ships
  VALUES ('Musashi', 'Yamato', 1942);

INSERT INTO Ships
  VALUES ('New Jersey', 'Iowa', 1943);

INSERT INTO Ships
  VALUES ('North Carolina', 'North Carolina', 1941);

INSERT INTO Ships
  VALUES ('Ramillies', 'Revenge', 1917);

INSERT INTO Ships
  VALUES ('Renown', 'Renown', 1916);

INSERT INTO Ships
  VALUES ('Repulse', 'Renown', 1916);

INSERT INTO SHIPS
  VALUES ('Resolution', 'Renown', 1916);

INSERT INTO Ships
  VALUES ('Revenge', 'Revenge', 1916);

INSERT INTO Ships
  VALUES ('Royal Oak', 'Revenge', 1916);

INSERT INTO Ships
  VALUES ('Royal Sovereign', 'Revenge', 1916);

INSERT INTO Ships
  VALUES ('Tennessee', 'Tennessee', 1920);

INSERT INTO Ships
  VALUES ('Washington', 'North Carolina', 1941);

INSERT INTO Ships
  VALUES ('Wisconsin', 'Iowa', 1944);

INSERT INTO Ships
  VALUES ('Yamato', 'Yamato', 1941);
  
INSERT INTO Ships
  VALUES ('Yamashiro', 'Yamato', 1947);
  
INSERT INTO Ships
  VALUES ('South Dakota', 'North Carolina', 1941);

INSERT INTO SHIPS
  VALUES ('Bismarck', 'North Carolina', 1911);
  
INSERT INTO Ships
  VALUES ('Duke of York', 'Renown', 1916);
  
INSERT INTO Ships
  VALUES ('Fuso', 'Iowa', 1940);
  
INSERT INTO Ships
  VALUES ('Hood', 'Iowa', 1942);
  
INSERT INTO Ships
  VALUES ('Rodney', 'Yamato', 1915);
  
INSERT INTO Ships
  VALUES ('Yanashiro', 'Yamato', 1918);
  
INSERT INTO Ships
  VALUES ('Schamhorst', 'North Carolina', 1917);
  
INSERT INTO Ships
  VALUES ('Prince of Wales', 'North Carolina', 1937);
  
INSERT INTO Ships
  VALUES ('King George V', 'Iowa', 1942);
  
INSERT INTO Ships
  VALUES ('West Virginia', 'Iowa', 1942);

----- Outcomes ----- 
INSERT INTO Outcomes
  VALUES ('Bismarck', 'North Atlantic', 'sunk'); 

INSERT INTO Outcomes
  VALUES ('California', 'Surigao Strait', 'ok');

INSERT INTO Outcomes
  VALUES ('Duke of York', 'North Cape', 'ok');

INSERT INTO Outcomes
  VALUES ('Fuso', 'Surigao Strait', 'sunk');

INSERT INTO Outcomes
  VALUES ('Hood', 'North Atlantic', 'sunk');

INSERT INTO Outcomes
  VALUES ('King George V', 'North Atlantic', 'ok');

INSERT INTO OUTCOMES
  VALUES ('Kirishima', 'Guadalcanal', 'sunk');

INSERT INTO OUTCOMES
  VALUES ('Prince of Wales', 'North Atlantic', 'damaged');

INSERT INTO OUTCOMES
  VALUES ('Rodney', 'North Atlantic', 'ok');

INSERT INTO OUTCOMES
  VALUES ('Schamhorst', 'North Cape', 'sunk');

INSERT INTO Outcomes
  VALUES ('South Dakota', 'Guadalcanal', 'damaged');

INSERT INTO Outcomes
  VALUES ('Tennessee', 'Surigao Strait', 'ok');

INSERT INTO Outcomes
  VALUES ('Washington', 'Guadalcanal', 'ok');

INSERT INTO Outcomes
  VALUES ('West Virginia', 'Surigao Strait', 'ok');

INSERT INTO Outcomes
  VALUES ('Yamashiro', 'Surigao Strait', 'sunk');

INSERT INTO Outcomes
  VALUES ('California', 'Guadalcanal', 'damaged');
