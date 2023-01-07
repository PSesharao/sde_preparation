

CREATE TABLE Customer (
cust_id integer,
cname varchar(225),
Address  varchar(225),
Gender char(2),
City  varchar(225),
Pincode integer,
TotalOrdersYet integer
);

INSERT INTO Customer
VALUES 	(546, 'Rakesh Matam', 'Bongora, kamrup rural', 'M', 'Guwahati', 781015, 3),
		(1111,'Kuldeep Ravaliya','Bongora, kamrup rural','M','Guwahati', 781015, 7),
        (670,'Sugam Sehgal','Lajpat Nagar','M','Jalandhar', 144001, 2),
        (1110,'Sumit Mishra','Bongora, kamrup rural','M','Guwahati', 781015, 1),
		(890,'Lokesh Daga','Ashok Nagar','M','Jalandhar', 144003, 4),
		(700,'Riya Gupta','Dilbagh Nagar','F','Jalandhar', 144002, 5),
		(1251,'Ram Kumar','Dilbagh Nagar','M','Jalandhar', 144002, 1),
		(1300,'Shayam Singh','Ludhiana H.O','M','Ludhiana', 141001, 15),
		(245,'Neelabh Shukla','Ashok Nagar','M','Jalandhar', 144003, 10),
		(210,'Barkha Singh','Dilbagh Nagar','F','Jalandhar', 144002, 1),
		(500,'Rohan Arora','Ludhiana H.O','M','Ludhiana', 141001, 7);

SELECT Gender FROM Customer GROUP BY Gender ; 

SELECT City , COUNT(*) AS Cust_num FROM Customer GROUP BY City ; 

SELECT Address , COUNT(*) AS Order_num FROM Customer GROUP BY Address ; 

SELECT Address , SUM(TotalOrdersYet) AS Order_num FROM Customer GROUP BY Address ; 

SELECT Pincode , MAX(TotalOrdersYet) FROM Customer GROUP BY Pincode ; 

SELECT Gender , MIN(TotalOrdersYet) FROM Customer GROUP BY Gender ; 

SELECT City , AVG(TotalOrdersYet) FROM Customer GROUP BY City ;

SELECT City , COUNT(*) AS Number FROM Customer GROUP BY City ORDER BY Number DESC ;

SELECT Address , COUNT(*) AS Address_times FROM Customer WHERE City = 'Jalandhar' GROUP BY Address  ;

SELECT Address , City , Pincode FROM Customer GROUP BY Address , City , Pincode HAVING COUNT(*) > 2 ;  

SELECT Address FROM Customer WHERE City = 'Guwahati' GROUP BY Address HAVING SUM(TotalOrdersYet) > 7 ;