package test;

import java.sql.Connection;
import java.sql.Date;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import pojo.Book;
import utils.DbUtils;

public class Program {
	public static void main(String[] args) {
		try( Connection connection = DbUtils.getConnection();
			Statement statement = connection.createStatement();)
		{
/*			int bookId = 1011;
			String subjectName = "Java";
			String bookName = "Java Head First";
			String authorName = "Kathy Siera";
			float price = 350.45f;
			Date date = Date.valueOf("2005-08-11");*/
			
			int bookId = 1012;
			String subjectName = "Operating System";
			String bookName = "Operating System Concept's";
			String authorName = "Galvin";
			float price = 800;
			Date date = Date.valueOf("2013-10-29");
				
			String sql = "insert into BookTable values("+bookId+",'"+subjectName+"','"+bookName+"','"+authorName+"',"+price+",'"+date+"')";
			int rowsAffected = statement.executeUpdate(sql);
			System.out.println(rowsAffected+" row(s) affected");
		}
		catch (SQLException e) 
		{			
			e.printStackTrace();
		}
		
	}
}
