DROP SCHEMA IF EXISTS animaldb;
CREATE SCHEMA animaldb;
USE animaldb;

DROP TABLE IF EXISTS users;

CREATE TABLE users
(
    id           INT(10) NOT NULL,
    email    VARCHAR(60) NOT NULL,
    password VARCHAR(60) BINARY NOT NULL
) DEFAULT CHARACTER SET=utf8mb4;

INSERT INTO users (id, email, password) VALUES (1, "wanictf21spring@gmail.com", "FAKE{ErrorBased}");
