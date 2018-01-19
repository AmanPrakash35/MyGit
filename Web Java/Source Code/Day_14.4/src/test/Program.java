package test;
import java.sql.*;

import pojo.Book;
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
				Book book = new Book();
				book.setBookId(rs.getInt("book_id"));
				
				book.setSubjectName(rs.getString("subject_name"));
				
				book.setBookName(rs.getString("book_name"));
				
				book.setAuthorName(rs.getString("author_name"));
				
				book.setPrice(rs.getFloat("price"));
				
				book.setPublishDate(rs.getDate("publish_date"));
				
				System.out.println(book.toString());
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
