DROP TABLE IF EXISTS address;
CREATE TABLE address (
     id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,
     town VARCHAR,
     street VARCHAR,
     house VARCHAR,
     note VARCHAR,
     user INTEGER
);

INSERT INTO address (town, street, house, note, user) VALUES ('Wembach', 'Schönhauser Allee', '94', '---', 1);
INSERT INTO address (town, street, house, note, user) VALUES ('Schleusingen', 'Oldesloer Strasse', '74', '---', 2);
INSERT INTO address (town, street, house, note, user) VALUES ('Hirschberg', 'Hollander Strasse', '39', '---', 3);
INSERT INTO address (town, street, house, note, user) VALUES ('Neuhemsbach', 'Grosse Praesidenten Str.', '45', '---', 4);
INSERT INTO address (town, street, house, note, user) VALUES ('Hoyerswerda', 'Lietzensee-Ufer', '62', '---', 4);
INSERT INTO address (town, street, house, note, user) VALUES ('Gerlingen', 'Kurfürstenstraße', '59', '---', 4);
INSERT INTO address (town, street, house, note, user) VALUES ('Theisbergstegen', 'Hardenbergstraße', '89', '---', 5);
INSERT INTO address (town, street, house, note, user) VALUES ('Epfenbach', 'Epfenbach', '37', '---', 6);