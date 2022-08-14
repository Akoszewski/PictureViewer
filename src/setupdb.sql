DROP TABLE IF EXISTS patients;

CREATE TABLE patients (
   id serial,
   name VARCHAR(20) NOT NULL,
   surname VARCHAR(20),
   age INT,
   PRIMARY KEY(id)
);

INSERT INTO patients (name, surname, age) VALUES ('Jan', 'Kowalski', 23);
INSERT INTO patients (name, surname, age) VALUES ('Janusz', 'Nowak', 54);

SELECT * FROM patients;
