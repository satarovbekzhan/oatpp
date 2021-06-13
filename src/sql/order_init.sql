DROP TABLE IF EXISTS "order";
CREATE TABLE "order" (
    id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,
    product INTEGER,
    user INTEGER,
    address INTEGER,
    amount INTEGER,
    timestamp DATETIME DEFAULT CURRENT_TIMESTAMP
);

-- INSERT INTO "order" (product, user, address, amount) VALUES (0, 0, 0, 0);