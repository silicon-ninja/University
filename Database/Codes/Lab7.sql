-- CREATING TABLES AND DESCRIBING IT..

CREATE table Team(Team_No int,Team_Name VARCHAR(40),primary key(Team_No));
CREATE table Player(Player_ID int AUTO_INCREMENT,Name VARCHAR(40) Not NULL,Team_No int not null,Score int,
primary key(Player_ID), FOREIGN KEY (Team_No) REFERENCES Team(Team_No));

desc player;
desc team;


-- INSERTING DATA INTO TEAM TABLE

insert into team values (1001,"Bangalore");
insert into team values (1002,"Jaipur");
insert into team values (1003,"Delhi");
select * from team;


-- INSERTING DATA INTO PLAYER TABLE

insert into Player(Name,Team_No,Score) values ("K Srikanth",1001,4000);
insert into Player(Name,Team_No,Score) values ("P Supraja",1001,3000);
insert into Player(Name,Team_No,Score) values ("Bhoomika JS",1001,3000);
insert into Player(Name,Team_No,Score) values ("Apoorva R",1001,3000);
insert into Player(Name,Team_No,Score) values ("Naveen Kumar GN",1002,3000);
insert into Player(Name,Team_No,Score) values ("Sushanth",1003,3000);

select * from player;

-- Question 1

select Name,Team_No from player as p1 where p1.Team_No = (select Team_No from player as play where play.name = "K Srikanth");

-- Question 2

select * from player as play where(play.score = (select max(score)from player as play2 where (play2.Team_No =1001)))

-- Question 3

 select * from player as play where (play.Team_No in (select Team_NO from team));

-- Question 4

select * from player as play,team as tm where play.Team_No = tm.Team_No;

-- Question 5

select * from player natural join team;

-- Question 6

select play.name,t.Team_Name from player as play left join team as t on play.Team_No = t.Team_No;

-- Question 7

select play.name,t.Team_Name from player as play right join team as t on play.Team_No = t.Team_No;






