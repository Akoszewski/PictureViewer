DROP TABLE IF EXISTS patients;

CREATE TABLE patients (
   id serial,
   name VARCHAR(50) NOT NULL,
   age INT,
   PRIMARY KEY(id)
);

INSERT INTO patients (name, age) VALUES ('Jan Kowalski', 23);
INSERT INTO patients (name, age) VALUES ('Janusz Nowak', 54);

SELECT * FROM patients;
