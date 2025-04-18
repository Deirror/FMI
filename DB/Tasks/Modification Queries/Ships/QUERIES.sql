USE Ships

-- Два британски бойни кораба от класа Nelson - Nelson и Rodney - са били пуснати на вода
-- едновременно през 1927 г. Имали са девет 16-инчови оръдия (bore) и водоизместимост от 34000
-- тона (displacement). Добавете тези факти към базата от данни
INSERT INTO Classes (class, type, country, numGuns, bore, displacement)
VALUES ('Nelson', 'bb', 'UK', 9, 16, 34000)

-- Изтрийте от таблицата Ships всички кораби, които са потънали в битка
DELETE FROM Ships
WHERE name IN (
    SELECT ship FROM Outcomes
    WHERE result='sunk'
)

-- Променете данните в релацията Classes така, че калибърът (bore) да се измерва в сантиметри
-- (вмомента е в инчове, 1 инч ~ 2.5 см) и водоизместимостта да се измерва в метрични тонове (1 м.т. = 1.1 т.)
UPDATE Classes
SET bore=bore * 2.5,
displacement=displacement * 1.1
