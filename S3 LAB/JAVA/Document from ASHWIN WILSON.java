import java.sql.*;
//java -cp .:mysql-connector-java-8.0.28.jar jdbcexample 
class jdbcexample{
	public static void main(String argv[]){
		try {
    			String url="jdbc:mysql://exam70@10.0.0.10:3306/exam70";
    			String username="exam70";
    			String psw="exam70";
    			
    			Connection conn = DriverManager.getConnection(url,username,psw);
    			Statement statement=conn.createStatement();
    	
    			statement.executeUpdate("insert into student(id,name) values(4,'sree')");
    			ResultSet result=statement.executeQuery("select * from student ");
    			//statement.executeUpdate("delete from mytable where 1");
    			
    			System.out.println("Database --");
    			while(result.next()){
    			  System.out.println(result.getString("id")+"----"+result.getString("name"));
    			}
		} catch (Exception ex) {
			    // handle any errors
		    System.out.println("SQLException: " + ex.getMessage());
		    
		}		
	}
}
