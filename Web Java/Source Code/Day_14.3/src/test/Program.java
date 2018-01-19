package test;
import java.sql.*;
public class Program
{
	public static final String URL = "jdbc:mysql://localhost:3306/dacdb";
	public static final String USER = "root";
	public static final String PASSWORD = "manager";
	public static void main(String[] args) 
	{
		Connection connection = null;
		Statement statement = null;
		try
		{
			Driver driver = new com.mysql.jdbc.Driver();
			DriverManager.registerDriver(driver);
		
			connection = DriverManager.getConnection(URL, USER, PASSWORD);
			
			statement = connection.createStatement();
			
			String sql = "select * from BookTable";
			
			ResultSet rs =  statement.executeQuery(sql);
			while( rs.next())
			{
				//int bookId = rs.getInt(1);
				int bookId = rs.getInt("book_id");
				//String subjectName =  rs.getString(2);
				String subjectName =  rs.getString("subject_name");
				//String bookName = rs.getString(3);
				String bookName = rs.getString("book_name");
				//String authorName = rs.getString(4);
				String authorName = rs.getString("author_name");
				//float price = rs.getFloat(5);
				float price = rs.getFloat("price");
				//Date publishDate = rs.getDate(6);
				Date publishDate = rs.getDate("publish_date");
				System.out.println(bookId+"	"+subjectName+"	"+bookName+"	"+authorName+"	"+price+"	"+publishDate);
			}
			rs.close();
		}
		catch (Exception e)
		{			
			e.printStackTrace();
		}
		finally
		{
			try 
			{
				statement.close();
				connection.close();
			}
			catch (SQLException e) 
			{				
				e.printStackTrace();
			}
		}
	}
}
