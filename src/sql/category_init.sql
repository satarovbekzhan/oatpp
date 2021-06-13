DROP TABLE IF EXISTS category;
CREATE TABLE category (
    id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,
    name VARCHAR
);

INSERT INTO category (name) VALUES ('Aktionsprodukte');
INSERT INTO category (name) VALUES ('KING''s Selection');
INSERT INTO category (name) VALUES ('Chicken');
INSERT INTO category (name) VALUES ('Fresh KINGs & mehr');
INSERT INTO category (name) VALUES ('KING Snacks');
