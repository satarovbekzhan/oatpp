DROP TABLE IF EXISTS ref_product_ingredient;
CREATE TABLE ref_product_ingredient (
    id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,
    product INTEGER,
    ingredient INTEGER
);
