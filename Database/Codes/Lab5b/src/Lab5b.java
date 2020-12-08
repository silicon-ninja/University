import java.math.BigInteger;
import java.sql.*;
import java.util.Scanner;
import java.sql.Connection;
import java.sql.DriverManager;
public class Lab5b {
    public static void main(String[] args) throws Exception {
    Scanner input = new Scanner(System.in);
    Class.forName("com.mysql.cj.jdbc.Driver");  
    Connection con=DriverManager.getConnection(  
    "jdbc:mysql://localhost:3306/lab5b","root","Sri123");  
    Statement stmt=con.createStatement();
    while(true) {
    System.out.println("") ;  
    System.out.println("**************** K Srikanth ****************") ;  
    System.out.println("") ;  
    System.out.println("Press 1 to Enter the Details to Database") ;   
    System.out.println("Press 2 to Display Detials Of Manager") ;  
    System.out.println("Press 3 to Count the No of Managers in each Location") ;  
    System.out.println("Press 4 to Display Each Manager Location") ;  
    int choice = input.nextInt();
    switch (choice) {
        // To Take input from user and store it in database
        case 1:
        System.out.println("") ;  
        System.out.println("Enter the Manager Name : ");
        String Name = input.next();
        System.out.println("Enter the Location : ");
        String Location = input.next();
        System.out.println("Enter the Phone Number  : ");
        BigInteger PhoNumber= input.nextBigInteger();
        stmt.executeUpdate("insert into manager(Manager_Name,Location,Phone_Number) values("+"'"+Name+"'"+","+"'"+Location+"'"+","+PhoNumber+")");
        break;
        // To print the manager_table in assending order 
        case 2:
        System.out.println("") ;  
        try{
        ResultSet rs=stmt.executeQuery("select * from manager order by Manager_Name ASC");  
        while(rs.next()) 
        System.out.println(rs.getInt(1)+"  "+rs.getString(2)+"  "+rs.getString(3)+"  "+rs.getString(4));  
        }catch(Exception e){ 
        System.out.println(e);}  
        break;
        
        case 3:
        System.out.println("") ;  
        try{
        ResultSet rs=stmt.executeQuery("select location,count(*) from manager group by location;");  
        while(rs.next()) 
        System.out.println(rs.getString(1)+"  "+rs.getString(2));  
        }catch(Exception e){ 
        System.out.println(e);}  
        break;

        case 4:
        System.out.println("") ;  
        try{
        ResultSet rs=stmt.executeQuery("select location,count(*) from manager group by location having count(*)> 3");  
        while(rs.next()) 
        System.out.println(rs.getString(1)+"  "+rs.getString(2)); 
        }catch(Exception e){ 
        System.out.println(e);}  
        break;

        default: System.out.println("Invalid Input Please Try Again");
            break;
        }
    }}}

    


 
  
