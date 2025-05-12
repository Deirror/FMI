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
