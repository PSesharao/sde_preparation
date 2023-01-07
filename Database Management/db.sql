



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
		
		

SELECT  Emp_name ,  Email FROM Emp_data WHERE Contract = 'Intern' ; 


SELECT * FROM Emp_data WHERE Dept = 'D3' AND Contract = 'FTE' ;

SELECT * FROM Emp_data WHERE Dept = 'D1' OR Dept = 'D3' ; 

SELECT * FROM Emp_data WHERE Dept IN ('D1' , 'D3'  ) ; 

SELECT * FROM Emp_data WHERE Dept NOT IN ('D1' , 'D2'  ) ; 

SELECT Emp_name , Dept FROM Emp_data WHERE HomeTown IN ('Mumbai' , 'Jalandhar' ) AND Emp_id < 900 ; 

SELECT * FROM Emp_data WHERE Email LIKE 'fab%' ; 

SELECT Emp_id , Emp_name FROM Emp_data WHERE Email LIKE '%bcd%' AND Dept IN ('D4' , 'D3'  ) AND HomeTown NOT IN ('Himachal' , 'Guwahati' ); 

