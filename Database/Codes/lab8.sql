-- Creating a Table "Offices"

create table offices(OfficeCode int AUTO_INCREMENT,
OfficeName varchar(20),
OfficePhone BIGINT,
City VARCHAR(20),
Country VARCHAR(20),
Primary Key (OfficeCode));

-- Inserting Data into Table "Offices"

insert into offices(OfficeName,OfficePhone,City,Country) values ("Bangalore",123131312,"Bangalore","India");
insert into offices(OfficeName,OfficePhone,City,Country) values ("Apple",123131312312,"Bangalore","India");
insert into offices(OfficeName,OfficePhone,City,Country) values ("Tesla",123131312,"Bangalore","India");
insert into offices(OfficeName,OfficePhone,City,Country) values ("Samsung",123131312,"Bangalore","India");

select * from offices;


-- Question A

delimiter @@

CREATE PROCEDURE counting(INOUT a INT,IN inc INT)
begin

    set a = a + inc;

end @@

set @count=0;
call counting(@count,200);
call counting(@count,300);
select @count;


--- Question B 

delimiter @@
CREATE PROCEDURE getPhNumber(IN Name VARCHAR(20))
begin 
    select OfficePhone from offices where OfficeName = Name;
end @@

call getPhNumber("Apple");


-- Question C

delimiter @@
CREATE PROCEDURE getTheCityCount(IN OfficeCountry VARCHAR(20))
begin 
    select count(*) from offices where Country = OfficeCountry ;
end @@

call getTheCityCount("India");

