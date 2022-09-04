DROP TABLE IF EXISTS patients;
DROP TABLE IF EXISTS exams;

CREATE TABLE patients (
   id serial,
   name VARCHAR(50) NOT NULL,
   gender VARCHAR(32),
   age INT,
   PRIMARY KEY(id)
);

CREATE TABLE exams (
   id serial,
   modality VARCHAR(3),
   filePath VARCHAR(1024),
   PRIMARY KEY(id)
);
