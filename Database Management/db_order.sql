CREATE TABLE IF NOT EXISTS e_transactions 
(
order_id text,
ordered_time date,
shipping_time date,
cost integer,
cust_id text
);
INSERT INTO e_transactions
VALUES 	('CN70101','2021-02-22','2021-02-28',5679,'Cid065'),
		('CN70102','2021-02-22','2021-02-25', 7999,'Cid019'),
		('CN70103','2021-06-14','2021-06-18', 1300,'Cid07'),
		('CN70104','2021-07-07','2021-07-11', 13299,'Cid098'),
		('CN70105','2021-07-07','2021-07-12', 1754,'Cid032');
		


SELECT order_id , ordered_time FROM e_transactions ORDER BY ordered_time ; 

SELECT * FROM e_transactions ORDER BY shipping_time DESC ; 

SELECT * FROM e_transactions ORDER BY ordered_time DESC , shipping_time ; 

SELECT * FROM e_transactions WHERE cost<5000 ORDER BY cost ; 

SELECT order_id , shipping_time FROM e_transactions WHERE ordered_time < '2021-06-30' ORDER BY cost , shipping_time DESC ; 



SELECT * FROM e_transactions WHERE (ordered_time BETWEEN '2021-02-00' AND '2021-02-28') 
UNION 
SELECT * FROM e_transactions WHERE (ordered_time BETWEEN '2021-07-00' AND '2021-07-31') ORDER BY cost ; 


SELECT * FROM e_transactions WHERE ordered_time IN ( '2021-02%' , '2021-07%' ) ; 

SELECT * FROM e_transactions WHERE ordered_time LIKE '2021-02%' OR ordered_time LIKE '2021-07%' ORDER BY cost ; 