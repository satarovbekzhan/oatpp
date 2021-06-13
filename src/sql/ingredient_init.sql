DROP TABLE IF EXISTS ingredient;
CREATE TABLE ingredient (
    id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,
    name VARCHAR
);

INSERT INTO ingredient (name) VALUES ('Bread');
INSERT INTO ingredient (name) VALUES ('Meat');
INSERT INTO ingredient (name) VALUES ('Onion');
INSERT INTO ingredient (name) VALUES ('Cheese');
INSERT INTO ingredient (name) VALUES ('Tomato');
INSERT INTO ingredient (name) VALUES ('Ketchup');