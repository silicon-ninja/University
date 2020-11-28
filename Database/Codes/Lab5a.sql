
-- Question 5.1
---------------------------------
create table manager_table(_ID int auto_increment, Name varchar(20),Department varchar(20),Address varchar(20),Salary VARCHAR(20),primary key (_ID));
desc manager_table;

insert into manager_table(name,Department,address,salary) values ("Srikanth","IT","Bangalore",100000);
insert into manager_table(name,Department,address,salary) values ("Naveen GN","IT","Bangalore",100000);
insert into manager_table(name,Department,address,salary) values ("Supraja P","IT","Bangalore",100000);
insert into manager_table(name,Department,address,salary) values ("Sushanth","CSE","Bangalore",100000);
select * from manager_table;

-- Question 5.2
---------------------------------
create VIEW srikanth_manager_view as SELECT Name,Department from manager_table where Department = "IT" ;
select * from srikanth_manager_view;


-- Question 5.3
---------------------------------
drop view srikanth_manager_view;




