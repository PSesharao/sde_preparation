
create table tutorials(
tutorial_title CHAR(255),
tutorial_author CHAR(255),
submission_date text
);

INSERT INTO tutorials(tutorial_title , tutorial_author , submission_date )
values("Learn MySQL" , "Balachandra Raju" , "01-09-2021") ; 

select * from tutorials ; 

INSERT INTO Students(Roll_no, std_name, Age) values ( 7, "Shantnu", 21) ; 

select * from Students ; 

UPDATE stud_data set Fname = 'Neelabh' , Age = 22 where roll_no = 17 ; 

select * from stud_data ; 

DELETE FROM products WHERE product_id in (596  , 700 ) ;
select * from products ;   

REPLACE INTO cities(id ,cname , population)
VALUES(4,"Phoenix" , 1768980 );
select * from cities ; 