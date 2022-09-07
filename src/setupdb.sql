DROP TABLE IF EXISTS patients CASCADE;
DROP TABLE IF EXISTS exams;

CREATE TABLE patients (
   id serial,
   name VARCHAR(64) NOT NULL,
   gender VARCHAR(32),
   age INT,
   patientIdentifier VARCHAR(16),
   PRIMARY KEY(patientIdentifier)
);

CREATE TABLE exams (
   id serial,
   patientIdentifier VARCHAR(16),
   modality VARCHAR(16),
   filePath VARCHAR(1024),
   acq_date VARCHAR (20),
   PRIMARY KEY(id),
   FOREIGN KEY(patientIdentifier) REFERENCES patients(patientIdentifier)
);
