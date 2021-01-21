-- Table 1 USER

-- create table user(
--         User_ID int auto_increment,
--         Password varchar (40) not null ,
--         First_Name  varchar (40) not null,
--         Last_Name varchar (40),
--         Phone_Number bigint unique not null ,
--         Address varchar(40),
--         primary key (User_ID));


-- Data Values for User Table 

-- insert into user(Password,FIRST_Name,Last_Name,Phone_Number,Address) values ("******","K","Srikanth",9493364308,"Nagwara,Bangalore");
-- insert into user(Password,FIRST_Name,Last_Name,Phone_Number,Address) values ("******","GN","Naveen Kumar",7019462108,"Bangalore");








-- Table 2 ADMIN

-- create table admin(
--         Admin_ID int,
--         Password varchar (40) not null ,
--         primary key (Admin_ID));


-- Data Values for Admin Table 

-- insert into admin values ("17002124","*******");







-- Table 3 Product

-- create table product(
--         Product_ID int auto_increment,
--         Product_Name varchar (40) not null ,
--         Manufacturer varchar (40) not null ,
--         Availability_Status Bool not null,
--         Description varchar (40) not null ,
--         Quantity int not null ,
--         Product_price Double not null ,
--         primary key (Product_ID));


-- Data Values for Product Table 

-- insert into product(Product_Name,Manufacturer,Availability_Status,Description,Quantity,Product_price) VALUES ("Oak Desk","IKEA",true,"Good Table",10,4000.00);
-- insert into product(Product_Name,Manufacturer,Availability_Status,Description,Quantity,Product_price) VALUES ("Maple Desk","IKEA",true,"Also a Good Table",5,10000.00);








-- Table 4 Orders

-- create table orders(
--         Order_ID int auto_increment,
--         User_ID int,
--         Product_ID int ,
--         Date_Time TIMESTAMP  DEFAULT CURRENT_TIMESTAMP,
--         FOREIGN KEY (User_ID) REFERENCES user(User_ID),
--         FOREIGN KEY (Product_ID) REFERENCES product(Product_ID),
--         primary key (Order_ID));



-- Data Values for Order Table 

-- insert into orders(user_ID,Product_ID) values (1,1);




-- Table 5 add_product

-- create table add_product(
--         Product_ID int,
--         Admin_ID int ,
--         Status bool not null,
--         FOREIGN KEY (Product_ID) REFERENCES product(Product_ID),
--         FOREIGN KEY (Admin_ID) REFERENCES admin(Admin_ID));



-- Data Values for add_product 

-- insert into add_product(Product_ID,Admin_ID,Status) values (1,17002124,true);







-- Table 6 update_product 


-- create table update_product(
--                 Product_ID int,
--                 Admin_ID int ,
--                 Status bool not null,
--                  FOREIGN KEY (Product_ID) REFERENCES product(Product_ID),
--                 FOREIGN KEY (Admin_ID) REFERENCES admin(Admin_ID));

-- Data Values for update_product 

-- insert into update_product(Product_ID,Admin_ID,Status) values (1,17002124,true);










-- Table 6 delete_product 

-- create table delete_product(
--                 Product_ID int,
--                 Admin_ID int ,
--                 Status bool not null,
--                  FOREIGN KEY (Product_ID) REFERENCES product(Product_ID),
--                 FOREIGN KEY (Admin_ID) REFERENCES admin(Admin_ID));


-- Data Values for delete_product 

-- insert into delete_product(Product_ID,Admin_ID,Status) values (1,17002124,true);










-- Constraints 

-- update user set Phone_Number = "GN "where Phone_Number = 7019462108;

-- update add_product set status = Null where status = true;

-- update orders set user_id = 7 where user_id = 1;

-- update orders set order_id= null where order_id = 1;