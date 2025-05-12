USE FLIGHTS

-- Създайте изглед, който извежда име на авиокомпания оператор на полета, номер на полет
-- и брой пътници, потвърдили резервация за този полет. Тествайте изгледa
  
CREATE VIEW v_flight_clients
(airline_operator, fnumber, clients_count)
AS SELECT FLIGHTS.AIRLINE_OPERATOR, FLIGHTS.FNUMBER, COUNT(BOOKINGS.CODE) FROM FLIGHTS
JOIN BOOKINGS
ON BOOKINGS.FLIGHT_NUMBER=FLIGHTS.FNUMBER
WHERE BOOKINGS.STATUS==1
GROUP BY FLIGHTS.AIRLINE_OPERATOR, FLIGHTS.FNUMBER;

-- Създайте изглед, който за всяка агенция извежда името на клиента с най-много резервации

CREATE VIEW v_top_client AS
SELECT 
    B.AGENCY AS agency_name,
    C.FNAME,
    C.LNAME
FROM BOOKINGS B
JOIN CUSTOMERS C ON C.ID = B.CUSTOMER_ID
WHERE B.STATUS = 1
  AND B.CUSTOMER_ID = (
    SELECT TOP 1 B2.CUSTOMER_ID
    FROM BOOKINGS B2
    WHERE B2.AGENCY = B.AGENCY AND B2.STATUS = 1
    GROUP BY B2.CUSTOMER_ID
    ORDER BY COUNT(*) DESC
  );

-- Създайте изглед за таблицата Agencies, който извежда всички данни за агенциите от град
-- София. Дефинирайте изгледa с CHECK OPTION

CREATE VIEW v_sofia_agencies
AS 
SELECT * FROM AGENCIES
WHERE CITY='Sofia'
WITH CHECK OPTION;

-- Създайте изглед за таблицата Agencies, който извежда всички данни за агенциите, такива
-- че телефонните номера на тези агенции да имат стойност NULL. Дефинирайте изгледa с CHECK OPTION
CREATE VIEW v_ph_agencies
AS 
SELECT * FROM AGENCIES
WHERE PHONE IS NULL
WITH CHECK OPTION;

-- Опитайте се да вмъкнете следните редове през изгледите от задачи 3 и 4. Какво се
-- случва?
INSERT INTO v_SF_Agencies
VALUES('T1 Tour', 'Bulgaria', 'Sofia','+359'); -- OK
INSERT INTO v_SF_PH_Agencies
VALUES('T2 Tour', 'Bulgaria', 'Sofia',null); -- OK
INSERT INTO v_SF_Agencies
VALUES('T3 Tour', 'Bulgaria', 'Varna','+359'); -- FAIL
INSERT INTO v_SF_PH_Agencies
VALUES('T4 Tour', 'Bulgaria', 'Varna',null); -- OK
INSERT INTO v_SF_PH_Agencies
VALUES('T4 Tour', 'Bulgaria', 'Sofia','+359'); -- FAIL

-- Кои от горните изгледи са updateable (т.е. върху тях могат да се изпълняват DML оператори)?
-- Отговор: sofia и phone - другите имат group by, join ...

-- Изтрийте създадените изгледи
DROP VIEW v_flight_clients;
DROP VIEW v_top_client;
DROP VIEW v_sofia_agencies;
DROP VIEW v_SF_Agencies;
DROP VIEW v_SF_PH_Agencies;
