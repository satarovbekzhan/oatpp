DROP TABLE IF EXISTS user;
CREATE TABLE user (
    id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,
    email VARCHAR UNIQUE,
    password VARCHAR,
    firstname VARCHAR,
    lastname VARCHAR,
    salutation VARCHAR,
    role VARCHAR
);

INSERT INTO user (email, password, firstname, lastname, salutation, role) VALUES ('satarovbekzhan@gmail.com', '123', 'Bekzhan', 'Satarov', 'Herr', 'ROLE_ADMIN');
INSERT INTO user (email, password, firstname, lastname, salutation, role) VALUES ('brenda.i.starkey@rhyta.com', '321', 'Brenda', 'Starkey', 'Frau', 'ROLE_MODERATOR');
INSERT INTO user (email, password, firstname, lastname, salutation, role) VALUES ('allenm.m.davis@armyspy.com', '321', 'Allen', 'Davis', 'Herr', 'ROLE_MODERATOR');
INSERT INTO user (email, password, firstname, lastname, salutation, role) VALUES ('wendy.b.herrera@dayrep.com', '213', 'Wendy', 'Herrera', 'Frau', 'ROLE_CUSTOMER');
INSERT INTO user (email, password, firstname, lastname, salutation, role) VALUES ('william.r.jasper@rhyta.com', '213', 'William', 'Jasper', 'Herr', 'ROLE_CUSTOMER');
INSERT INTO user (email, password, firstname, lastname, salutation, role) VALUES ('socorro.c.fries@teleworm.us', '213', 'Socorro', 'Fries', 'Frau', 'ROLE_CUSTOMER');
