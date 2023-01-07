CREATE TABLE Employee
(
   EmpCode      INT,
   EmpName		VARCHAR(30),
   Job          VARCHAR(45),
   Manager      CHAR(4),
   HireDate     DATE,
   Salary       INT,
   DeptCode     INT
);

INSERT INTO Employee (EmpCode,EmpName,Job,Manager,HireDate,Salary,DeptCode)
VALUES (9369, 'Ted Mosby', 'SOFTWARE ENGINEER', 7902, '1980-12-17', 2800,20),
       (9499, 'Robin Scherbatsky', 'SALESMAN', 7698, '1981-02-20', 1600,30),    
       (9566, 'Lily Aldrin', 'MANAGER', 7839, '1981-04-02', 3570,20),
       (9654, 'Phoebe Buffay', 'SALESMAN', 7698, '1981-09-28', 1250, 30),
       (9782, 'Monica Geller', 'MANAGER', 7839, '1981-06-09', 2940,10),
       (9788, 'Chandler Bing', 'ANALYST', 7566, '1982-12-09', 3000,20),
       (9839, 'Marshall Eriksen', 'PRESIDENT', 7566, '1981-11-17', 5000, 10);
	   

SELECT EmpName FROM Employee WHERE Salary > (
SELECT Salary FROM Employee WHERE EmpName = 'Monica Geller'
);

SELECT EmpName , Salary , DeptCode , Job  FROM Employee WHERE Job = (
SELECT Job FROM Employee WHERE EmpName = 'Phoebe Buffay' 
) ; 

SELECT EmpName , DeptCode FROM Employee WHERE EXISTS (
SELECT EmpCode FROM Employee WHERE Salary > 4000 
) ; 

SELECT * FROM (select EmpCode , EmpName , Salary , Salary*12 as A_Sal FROM Employee ) t WHERE t.A_Sal > 30000 

select EmpCode , EmpName , Salary FROM Employee WHERE Salary > ( select avg(Salary ) FROM Employee ) and EmpName like "%e%" ; 