package test;
import java.io.InputStream;
import java.sql.*;
import java.util.Properties;

import pojo.Book;
public class Program
{

	public static void main(String[] args) 
	{
		Connection connection = null;
		Statement statement = null;
		try
		{
			InputStream inputStream = Program.class.getClassLoader().getResourceAsStream("Config.properties");
			Properties prop = new Properties();
			prop.load(inputStream );
			
			//Class.forName(prop.getProperty("DRIVER"));
		
			connection = DriverManager.getConnection(prop.getProperty("URL"), prop.getProperty("USER"), prop.getProperty("PASSWORD"));
			
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
