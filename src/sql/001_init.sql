
CREATE TABLE users (
                         id          INTEGER PRIMARY KEY,
                         email       VARCHAR UNIQUE,
                         password    VARCHAR UNIQUE,
                         firstname   VARCHAR,
                         lastname    VARCHAR,
                         salutation  VARCHAR,
                         role        VARCHAR
);


INSERT INTO users (email, password, firstname, lastname, salutation, role)
            VALUES ('bs@gmail.com', '123', 'Bekzhan', 'Satarov', 'Herr', 'ROLE_ADMIN');
INSERT INTO users (email, password, firstname, lastname, salutation, role)
            VALUES ('jd@yahoo.org', '321', 'John', 'Doe', 'Herr', 'ROLE_MODERATOR');
INSERT INTO users (email, password, firstname, lastname, salutation, role)
            VALUES ('cs@outlook.mi', '213', 'Kristen', 'Stewart', 'Frau', 'ROLE_CUSTOMER');
