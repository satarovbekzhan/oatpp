DROP TABLE IF EXISTS ref_product_category;
CREATE TABLE ref_product_category (
    id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,
    product INTEGER,
    category INTEGER
);