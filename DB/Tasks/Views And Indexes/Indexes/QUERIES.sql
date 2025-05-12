USE FLIGHTS

-- Създайте подходящ/и индекс/и върху таблицата Product от базата от данни PC
  
CREATE NONCLUSTERED INDEX idx_product_maker
ON product(maker);

CREATE NONCLUSTERED INDEX idx_product_type
ON product(type);

CREATE NONCLUSTERED INDEX idx_product_maker_type
ON product(maker, type);

-- Създайте подходящи индекси върху таблиците Classes, Ships, Battles, Outcomes от базата от данни Ships

-- BATTLES Table Indexes
CREATE NONCLUSTERED INDEX idx_battles_date
ON BATTLES(DATE);

CREATE NONCLUSTERED INDEX idx_battles_name
ON BATTLES(NAME);

-- CLASSES Table Indexes
CREATE NONCLUSTERED INDEX idx_classes_class
ON CLASSES(CLASS);

CREATE NONCLUSTERED INDEX idx_classes_country_type
ON CLASSES(COUNTRY, TYPE);

CREATE NONCLUSTERED INDEX idx_classes_numguns
ON CLASSES(NUMGUNS);

-- SHIPS Table Indexes
CREATE NONCLUSTERED INDEX idx_ships_class
ON SHIPS(CLASS);

CREATE NONCLUSTERED INDEX idx_ships_launched
ON SHIPS(LAUNCHED);

CREATE NONCLUSTERED INDEX idx_ships_name_class
ON SHIPS(NAME, CLASS);

-- OUTCOMES Table Indexes
CREATE NONCLUSTERED INDEX idx_outcomes_ship_battle
ON OUTCOMES(SHIP, BATTLE);

CREATE NONCLUSTERED INDEX idx_outcomes_result
ON OUTCOMES(RESULT);

-- Изтрийте създадените индекси

-- Drop indexes on BATTLES table
DROP INDEX idx_battles_date ON BATTLES;
DROP INDEX idx_battles_name ON BATTLES;

-- Drop indexes on CLASSES table
DROP INDEX idx_classes_class ON CLASSES;
DROP INDEX idx_classes_country_type ON CLASSES;
DROP INDEX idx_classes_numguns ON CLASSES;

-- Drop indexes on SHIPS table
DROP INDEX idx_ships_class ON SHIPS;
DROP INDEX idx_ships_launched ON SHIPS;
DROP INDEX idx_ships_name_class ON SHIPS;

-- Drop indexes on OUTCOMES table
DROP INDEX idx_outcomes_ship_battle ON OUTCOMES;
DROP INDEX idx_outcomes_result ON OUTCOMES;
