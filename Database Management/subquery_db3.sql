CREATE TABLE sailors
    (
      sid integer,
      sname varchar(20),
      rating integer,
      age integer
    );

CREATE TABLE boats
    (
        bid integer,
        bname varchar(20),
        color varchar(20)
    );
    
    
insert into sailors values(22,'dustin',7,25);
insert into sailors values(29,'brutus',1,33);
insert into sailors values(31,'lubber',79,55);
insert into sailors values(32,'andy',8,25);
insert into sailors values(58,'rusty',10,35);
insert into sailors values(58,'buplb',10,55);
insert into sailors values(58,'buplerb',10,35);
insert into sailors values(22,'bb',10,55);
insert into sailors values(11,'buplb',4,55);
insert into sailors values(07,'buplerb',6,35);


insert into boats values(101,'interlake','blue');
insert into boats values(102,'interlake','red');
insert into boats values(103,'clipper','green');
insert into boats values(104,'marine','red');

CREATE TABLE reserves
    (
        sid integer,
        bid integer,
        daytook date
    );

insert into reserves values(22,101,'2004-01-01');
insert into reserves values(22,102,'2004-01-01');
insert into reserves values(22,103,'2004-02-01');
insert into reserves values(22,105,'2004-02-01');
insert into reserves values(31,103,'2005-05-05');
insert into reserves values(32,104,'2005-04-07');

SELECT sname , age FROM sailors WHERE age = 
(SELECT MAX(age) FROM sailors ) ; 


SELECT bname , color FROM boats WHERE bid IN (
SELECT bid FROM reserves WHERE sid IN (
SELECT sid FROM sailors WHERE age = ( SELECT MIN(age) FROM sailors )
)
) ; 

SELECT sid , daytook FROM reserves WHERE sid IN (
SELECT sid FROM sailors WHERE rating = ( SELECT MAX(rating) FROM sailors )
) ; 

SELECT s.sid,s.sname FROM sailors s WHERE s.sid IN ( SELECT s.sid FROM sailors s,boats b,reserves r WHERE s.sid=r.sid AND b.bid=r.bid GROUP BY s.sid HAVING COUNT(b.bid)>1 );

SELECT sid FROM sailors where salary < () 