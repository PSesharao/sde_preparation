CREATE TABLE Empdept1
(
   EmpCode      INT,
   EmpFName     CHAR(15),
   EmpLName     CHAR(15),
   Job          CHAR(45)
);

INSERT INTO Empdept1 (EmpCode,EmpFname,EmpLname, Job)
VALUES (9369, 'TONY', 'STARK', 'SOFTWARE ENGINEER'),
       (9499, 'TIM', 'ADOLF', 'SALESMAN'),   
       (9566, 'KIM', 'JARVIS', 'MANAGER'),
       (9654, 'SAM', 'MILES', 'SALESMAN');
       
       
CREATE TABLE Empdept2 
(
   EmpCode      INT,
   EmpFName     CHAR(15),
   EmpLName     CHAR(15),
   Job          CHAR(45)
);

INSERT INTO Empdept2 (EmpCode,EmpFname,EmpLname, Job)
VALUES (9566, 'KIM', 'JARVIS', 'MANAGER'),
       (9902, 'ANDREW', 'FAULKNER', 'ANALYST'),   
       (9685, 'SAMAY', 'DAGA', 'SALESMAN');
	   
	   
SELECT EmpCode , EmpFname , EmpLname , Job FROM Empdept1 
UNION 
SELECT EmpCode , EmpFname , EmpLname , Job FROM Empdept2 ;  

SELECT * FROM (SELECT EmpCode , EmpFname , EmpLname , Job FROM Empdept1 
UNION ALL
SELECT EmpCode , EmpFname , EmpLname , Job FROM Empdept2 ) t
WHERE Job = 'SALESMAN' ;  


SELECT * FROM (SELECT  EmpFname , EmpLname , EmpCode FROM Empdept1 
UNION ALL 
SELECT EmpFname , EmpLname , EmpCode FROM Empdept2 ) t 
ORDER BY EmpCode ; 


SELECT DISTINCT EmpCode , EmpFname , EmpLname , Job FROM Empdept1 
INNER JOIN Empdept2 USING(EmpCode , EmpFname , EmpLname , Job); 

SELECT EmpCode , EmpFname , EmpLname , Job FROM Empdept2 ; 


SELECT EmpCode , EmpFname , EmpLname , Job FROM Empdept1 
MINUS 
SELECT EmpCode , EmpFname , EmpLname , Job FROM Empdept2 ; 


SELECT 
    Empdept1.EmpCode , Empdept1.EmpFname , Empdept1.EmpLname , Empdept1.Job
FROM 
    Empdept1
LEFT JOIN Empdept2 
    ON (Empdept1.EmpCode = Empdept2.EmpCode )
WHERE 
    Empdept2.EmpCode IS NULL; 
	
