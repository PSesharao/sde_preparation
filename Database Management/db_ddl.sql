

CREATE TABLE IF NOT EXISTS Emp_data (
Emp_id integer,
Emp_name text,
Dept  text,
Contract  text,
Email  text,
HomeTown text
);

INSERT INTO Emp_data
VALUES 	(546, 'Rakesh Matam', 'D1', 'FTE','fabcd1@xyz.com', 'Patna'),
		(1111,'Kuldeep Ravaliya','D3','Intern','intdef1@xyz.com','Indore'),
        (670,'Sugam Sehgal','D4','FTE','fabcd3@xyz.com','Himachal'),
        (1110,'Sumit Mishra','D3','Intern','intdef2@xyz.com','Patna'),
		(890,'Lokesh Daga','D2','FTE','fabcd5@xyz.com','Bikaner'),
		(700,'Rakesh Matam','D3','FTE','fabcd6@xyz.com','Ludhiana'),
		(1251,'Ram Kumar','D4','FTE','fabcd7@xyz.com','Guwahati'),
		(1300,'Shayam Singh','D2','Intern','intdef3@xyz.com','Ludhiana'),
		(245,'Neelabh Shukla','D4','FTE','fabcd8@xyz.com','Kota'),
		(210,'Barkha Singh','D3','FTE','fabcd9@xyz.com','Mumbai'),
		(500,'Rohan Arora','D5','Intern','intdef4@xyz.com','Jalandhar');


CREATE TABLE IF NOT EXISTS People (
pid INTEGER,
lastname varchar(255),
firstname  varchar(255),
address  varchar(255),
city  varchar(255)
);

SELECT table_name, column_name, data_type
FROM information_schema.columns
WHERE table_name = 'People'
ORDER BY column_name;


CREATE TABLE IF NOT EXISTS Patients (
patient_id INTEGER PRIMARY KEY,
patient_title char(25) NOT NULL,
patient_name  char(25) NOT NULL ,
admit_date date 
);

SELECT table_name, column_name, data_type
FROM information_schema.columns
WHERE table_name = 'Patients'
ORDER BY column_name;

CREATE TABLE IF NOT EXISTS users  (
id INTEGER PRIMARY KEY,
full_name varchar(255) ,
enabled char(25)  ,
last_login date 
);

SELECT table_name, column_name, data_type
FROM information_schema.columns
WHERE table_name = 'users';


CREATE TABLE IF NOT EXISTS addresses   (
user_id INTEGER PRIMARY KEY,
street varchar(255) NOT NULL,
city varchar(255) NOT NULL ,
state varchar(255) NOT NULL , 
FOREIGN KEY (user_id) REFERENCES users(id)
);

SELECT table_name, column_name, data_type
FROM information_schema.columns
WHERE table_name = 'addresses';


CREATE TABLE IF NOT EXISTS books   (
id INTEGER PRIMARY KEY,
title varchar(100) ,
author varchar(100) ,
published_date TIMESTAMP ,
isbn char(12) UNIQUE 
);

SELECT table_name, column_name, data_type
FROM information_schema.columns
WHERE table_name = 'books';


CREATE TABLE IF NOT EXISTS reviews    (
id INTEGER PRIMARY KEY,
book_id INTEGER , 
reviewer_name varchar(225),
content varchar(225) ,
rating INTEGER , 
published_date  TIMESTAMP ,
FOREIGN KEY (book_id) REFERENCES books(id)
);

SELECT table_name, column_name, data_type
FROM information_schema.columns
WHERE table_name = 'reviews';


CREATE TABLE IF NOT EXISTS customer (
id INTEGER PRIMARY KEY,
name varchar(50) NOT NULL ,
city varchar(50) NOT NULL 
);

CREATE TABLE IF NOT EXISTS contacts (
id INTEGER PRIMARY KEY,
customer_id INTEGER , 
customer_info varchar(50) NOT NULL ,
customer_type varchar(50) NOT NULL , 
FOREIGN KEY (customer_id) REFERENCES customer(id)
);

DESC customer ; 
DESC contacts ; 


ALTER TABLE members
ADD cc_number varchar(255);

    SELECT table_name, column_name, data_type
    FROM information_schema.columns
    WHERE table_name = 'members'
    ORDER BY column_name;
	
ALTER TABLE Bank
RENAME COLUMN person_id TO Pid ;

ALTER TABLE Bank
MODIFY COLUMN Pid varchar(50) ;

ALTER TABLE members
DROP COLUMN member_dob;

    SELECT table_name, column_name, data_type
    FROM information_schema.columns
    WHERE table_name = 'members'
    ORDER BY column_name;
	
ALTER TABLE consumers 
RENAME TO Consumer_Data;

    SELECT table_name, column_name, data_type
    FROM information_schema.columns
    WHERE table_name = 'Consumer_Data'
    ORDER BY column_name;

ALTER TABLE customer
DROP COLUMN last_login;

ALTER TABLE customer
RENAME COLUMN full_name TO customer_name ;

