CREATE TABLE Client_d
(
ClientID CHAR(10),
ClientFname CHAR(100),
ClientLname CHAR(100),
Age INT,
ClientEmailID CHAR(200),
PhoneNo CHAR(10),
City CHAR(20),
EmpID CHAR(5)
);

INSERT INTO Client_d
VALUES ('1','Steve','Rogers',47,'steve@avg.com','986674443','Kolkata','3'),
		('2','Dustin','Poirier',27,'dustin@ufc.com','996767643','Kolkata','3'),
		('3','Avinash','Jain',24,'avinash@leg.com','876588971','Delhi','1'),
		('4','Sushant','Aggarwal',23,'sushant@tek.com','744355585','Hyderabad','5'),
		('5','Param','Singh',36,'param@xyz.com','674445556','Mumbai','2');

CREATE TABLE Project
(
ProjectID CHAR(10),
EmpID CHAR(5),
ProjectName CHAR(200) NULL,
ProjectStartDate DATE NULL,
ClientID CHAR(10)
);

INSERT INTO Project
VALUES ('100','1','pro_1','2021-04-21','3'),
		('200','2','pro_2','2021-03-12','1'),
		('300','3','pro_3','2021-01-16','5'),
		('400','3','pro_4','2021-04-27','2'),
		('500','5','pro_5','2021-05-01','4'),
		('600','9','pro_6','2021-01-19','1'),
		('700','7','pro_7','2021-08-27','2'),
		('800','8','pro_8','2021-09-15','3');

CREATE TABLE Employee
(
EmpID CHAR(5),
EmpFname CHAR(100) NULL,
EmpLname CHAR(100) NULL,
Age INT NULL,
EmailID CHAR(200) NULL,
PhoneNo CHAR(12) NULL,
City CHAR(20) NULL 
);

INSERT INTO Employee
VALUES ('1','Riya','Khanna',21,'riya@abc.com','987655443','Delhi'),
		('2','Sahil','Kumar',32,'sahil@abc.com','987657643','Mumbai'),
		('3','Vishwas','Aanand',24,'vishwas@abc.com','987658871','Kolkata'),
		('4','Harleen','Kaur',27,'harleen@abc.com','987677585','Bengaluru'),
		('5','Priyanshu','Gupta',23,'priyanshu@abc.com','956758556','Hyderabad');



SELECT Employee.EmpID , EmpFname , EmpLname , Project.ProjectID , Project.ProjectName 
FROM Employee INNER JOIN Project ON Employee.EmpID = Project.EmpID ;   

SELECT Employee.EmpID , EmailID ,  Employee.PhoneNo , ClientFname , ClientLname 
FROM Employee INNER JOIN Client_d ON Employee.EmpID = Client_d.EmpID WHERE Employee.City = 'Delhi' OR Client_d.City = 'Kolkata' ;   

SELECT ProjectName , ClientEmailID FROM Project INNER JOIN Client_d ON  Project.ClientID = Client_d.ClientID WHERE 
ProjectStartDate > '2021-04-01' ORDER BY Age DESC ; 

SELECT EmpFname ,  EmpLname , Project.ProjectID , Project.ProjectName FROM Employee LEFT JOIN  Project ON Project.EmpID =  Employee.EmpID  ; 

SELECT ProjectID , ProjectName , EmpFname , EmpLname , EmailID FROM Employee RIGHT JOIN Project ON Project.EmpID =  Employee.EmpID  ; 

SELECT c.ClientID , ClientFname , ClientLname , ClientEmailID , ProjectID , ProjectName FROM Client_d c RIGHT JOIN Project p 
ON c.ClientID = p.ClientID WHERE c.Age BETWEEN 25 AND 35 ORDER BY c.Age; 

SELECT EmpFname ,  EmpLname , ProjectID FROM Employee CROSS JOIN Project ; 


SELECT ProjectID , ProjectName , EmpFname , EmpLname , EmailID FROM Project LEFT JOIN Employee ON Employee.EmpID = Project.EmpID 

UNION 

SELECT ProjectID , ProjectName , EmpFname , EmpLname , EmailID FROM Project RIGHT JOIN Employee ON Employee.EmpID = Project.EmpID ; 