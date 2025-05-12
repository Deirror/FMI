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

-- Test
SELECT * FROM v_flight_clients;
