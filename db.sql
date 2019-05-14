DROP DATABASE serial;
CREATE DATABASE serial;

USE serial;

CREATE TABLE people_count (
  id_people_count INT NOT NULL,
  time VARCHAR(45) NULL,
  num VARCHAR(45) NULL,
  locate_id INT NULL,
  data_josn VARCHAR(45) NULL,
  PRIMARY KEY (id_people_count));

INSERT INTO people_count (
      id_people_count, time, num, locate_id, data_josn) 
      VALUES (1, '1', '1', '1', '1');
