DROP TABLE IF EXISTS patients;

CREATE TABLE patients (
   id serial,
   name VARCHAR(50) NOT NULL,
   gender VARCHAR(1)
   age INT,
   PRIMARY KEY(id)
);

CREATE TABLE exams (
   id serial,
   modality VARCHAR(3),
   filePath VARCHAR(1024),
   PRIMARY KEY(id)
);

INSERT INTO patients (name, gender, age) VALUES ('Jan Kowalski', 'M', 23);
INSERT INTO patients (name, gender, age) VALUES ('Janusz Nowak', 'K', 54);

INSERT INTO exams (modality, filePath) VALUES ('mod', 'path/to/file');
