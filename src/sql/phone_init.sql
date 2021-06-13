DROP TABLE IF EXISTS phone;
CREATE TABLE phone (
    id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,
    number VARCHAR,
    user INTEGER
);

INSERT INTO phone (number, user) VALUES ('+49 30 250825184', 1);
INSERT INTO phone (number, user) VALUES ('+49 30 406739609', 2);
INSERT INTO phone (number, user) VALUES ('+49 30 197152297', 3);
INSERT INTO phone (number, user) VALUES ('30 406739609', 3);
INSERT INTO phone (number, user) VALUES ('+49 30 823557960', 4);
INSERT INTO phone (number, user) VALUES ('+49 30 367295221', 5);
INSERT INTO phone (number, user) VALUES ('30 823557960', 5);
INSERT INTO phone (number, user) VALUES ('30 367295221', 5);
INSERT INTO phone (number, user) VALUES ('+49 30 272568609', 6);
INSERT INTO phone (number, user) VALUES ('30 272568609', 6);