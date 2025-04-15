-- а) Нека да създадем мини вариант на Facebook. Искаме да имаме следните релации (може да предложите и друг вариант): 
--   - Users: уникален номер (id), email, парола, дата на регистрация.
CREATE TABLE Users(
    id INT PRIMARY KEY, -- or UNIQUE
    email VARCHAR(50),
    password VARCHAR(75),
    data_signup DATE
);

--   - Friends: двойки от номера на потребители, напр. ако 12 е приятел на 21, 25 и 40, ще има кортежи (12,21), (12,25), (12,40).
CREATE TABLE Friends(
    id_from INT NOT NULL,
    id_to INT NOT NULL,
  
    PRIMARY KEY (id_from, id_to),
    FOREIGN KEY (id_from) REFERENCES Users(id),
    FOREIGN KEY (id_to) REFERENCES Users(id)
);

--   - Walls: номер на потребител, номер на потребител написал съобщението, текст на съобщението, дата.
CREATE TABLE Walls (
    id INT PRIMARY KEY,
    poster_id INT,
    content TEXT,
    date_posted DATETIME NOT NULL DEFAULT GETDATE(),

    FOREIGN KEY (wall_owner_id) REFERENCES Users(id),
    FOREIGN KEY (poster_id) REFERENCES Users(id)
);

--   - Groups: уникален номер, име, описание (по подразбиране - празен низ).
CREATE TABLE Groups (
    id INT PRIMARY KEY,
    name VARCHAR(70),
    description TEXT DEFAULT ''
);

--   - GroupMembers: двойки от вида номер на група - номер на потребител.
CREATE TABLE Groups (
    group_id INT,
    user_id INT,

    PRIMARY KEY (group_id, user_id),
    FOREIGN KEY (group_id) REFERENCES Groups(id),
    FOREIGN KEY (user_id) REFERENCES Users(id)
);

-- б) Добавете кортежи с примерни данни към новосъздадените релации
INSERT INTO Users (id, email, password, date_signup) VALUES
(1, 'alice@example.com', 'password123', '2024-01-15'),
(2, 'bob@example.com', 'secure456', '2024-02-01'),
(3, 'carol@example.com', 'hello789', '2024-03-10'),
(4, 'dave@example.com', 'pass999', '2024-04-05');

INSERT INTO Friends (id_from, id_to) VALUES
(1, 2),
(1, 3),
(2, 1),
(3, 2),
(4, 1);

INSERT INTO Walls (wall_owner_id, poster_id, content, date_posted) VALUES
(1, 2, 'Hey Alice! How are you?', '2024-02-02 10:00:00'),
(1, 3, 'Let’s catch up soon!', '2024-02-03 14:30:00'),
(2, 1, 'Thanks for the add!', '2024-02-04 09:00:00'),
(4, 2, 'Welcome Dave!', '2024-04-06 12:00:00');

INSERT INTO Groups (id, name, description) VALUES
(1, 'Gamers United', 'A group for all gaming enthusiasts'),
(2, 'Book Club', 'Let’s read and discuss!'),
(3, 'Car Lovers', 'Share your favorite rides!'),
(4, 'Silent Group', '');

INSERT INTO GroupMembers (group_id, user_id) VALUES
(1, 1),
(1, 2),
(2, 3),
(2, 1),
(3, 4),
(3, 2),
(4, 1);
