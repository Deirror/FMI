USE FLIGHTS

-- Добавете нова колона num_pass към таблицата Flights, която ще съдържа броя на
-- пътниците, потвърдили резервация за съответния полет

ALTER TABLE FLIGHTS
ADD num_pass INT DEFAULT 0
  
-- Добавете нова колона num_book към таблицата Agencies, която ще съдържа броя на
-- резервациите към съответната агенция
  
ALTER TABLE AGENCIES
ADD num_book INT DEFAULT 0

-- Създайте тригер за таблицата Bookings, който да се задейства при вмъкване на
-- резервация в таблицата и да увеличава с единица броя на пътниците, потвърдили
-- резервация за таблицата Flights, както и броя на резервациите към съответната агенция

CREATE TRIGGER trg_Bookings_Insert
ON BOOKINGS
AFTER INSERT
AS
BEGIN
    -- Увеличи броя на потвърдените пътници, ако status = 1
    UPDATE FLIGHTS
    SET num_pass = num_pass + 1
    FROM FLIGHTS f
    JOIN inserted i ON f.FNUMBER = i.FLIGHT_NUMBER
    WHERE i.STATUS = 1;

    -- Увеличи броя на резервациите в агенцията
    UPDATE AGENCIES
    SET num_book = num_book + 1
    FROM AGENCIES a
    JOIN inserted i ON a.NAME = i.AGENCY;
END;

-- Създайте тригер за таблицата Bookings, който да се задейства при изтриване на
-- резервация в таблицата и да намалява с единица броя на пътниците, потвърдили
-- резервация за таблицата Flights, както и броя на резервациите към съответната агенция

CREATE TRIGGER trg_Bookings_Delete
ON BOOKINGS
AFTER DELETE
AS
BEGIN
    -- Намали броя на потвърдените пътници, ако status = 1
    UPDATE FLIGHTS
    SET num_pass = num_pass - 1
    FROM FLIGHTS f
    JOIN deleted d ON f.FNUMBER = d.FLIGHT_NUMBER
    WHERE d.STATUS = 1;

    -- Намали броя на резервациите в агенцията
    UPDATE AGENCIES
    SET num_book = num_book - 1
    FROM AGENCIES a
    JOIN deleted d ON a.NAME = d.AGENCY;
END;

-- Създайте тригер за таблицата Bookings, който да се задейства при обновяване на
-- резервация в таблицата и да увеличава или намалява с единица броя на пътниците,
-- потвърдили резервация за таблицата Flights при промяна на статуса на резервацията

CREATE TRIGGER trg_Bookings_Update
ON BOOKINGS
AFTER UPDATE
AS
BEGIN
    -- Ако статус се е променил от 0 на 1 (непотвърдена → потвърдена)
    UPDATE FLIGHTS
    SET num_pass = num_pass + 1
    FROM FLIGHTS f
    JOIN inserted i ON f.FNUMBER = i.FLIGHT_NUMBER
    JOIN deleted d ON d.CODE = i.CODE
    WHERE d.STATUS = 0 AND i.STATUS = 1;

    -- Ако статус се е променил от 1 на 0 (потвърдена → непотвърдена)
    UPDATE FLIGHTS
    SET num_pass = num_pass - 1
    FROM FLIGHTS f
    JOIN inserted i ON f.FNUMBER = i.FLIGHT_NUMBER
    JOIN deleted d ON d.CODE = i.CODE
    WHERE d.STATUS = 1 AND i.STATUS = 0;
END;
