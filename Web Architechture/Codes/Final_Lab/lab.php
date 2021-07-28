<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Nginx Online Store</title>
    </head>
    <body>
        <?php
         $con = mysqli_connect("localhost","root","","lab_exam");
                 if (mysqli_connect_errno())
                    {
                    echo "Failed to connect to MySQL: " . mysqli_connect_error();
                    }
                    
                    $sql="select * from store where discount > 20";                    
                    $result=mysqli_query($con,$sql);
                    
                    echo "<table style='width:50%' border='1'>
                        <tr>
                        <th>Product_ID</th>
                        <th>Name</th>
                        <th>Manufacturer</th> 
                        <th>Price</th>
                        <th>Discount</th>
                        <th>Discount</th>
                        </tr>";
                        if(mysqli_num_rows($result)>0){
                            while($row=mysqli_fetch_assoc($result)){
                                echo "<tr>";
                                echo "<td><center>".$row["Product_ID"]."</center></td>";
                                echo "<td><center>".$row["Name"]."</center></td>";
                                echo "<td><center>".$row["Manufacturer"]."</center></td>";
                                echo "<td><center>".$row["Price"]."</center></td>";
                                echo "<td><center>".$row["Discount"]."</center></td>";
                                echo "<td><center>".$row["Description"]."</center></td>";
                                echo "</tr>";


                            }
                        }
                            else{
                                echo "Failed to load the NginX store";
                            }
        ?>

    </body>
</html>

