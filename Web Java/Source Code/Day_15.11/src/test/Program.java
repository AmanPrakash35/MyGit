package test;

import java.sql.Connection;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import pojo.Book;
import utils.DbUtils;

public class Program {
	public static void main(String[] args) {
		
		try( Connection connection = DbUtils.getConnection();
			PreparedStatement statement = connection.prepareStatement("insert into BookTable values(?,?,?,?,?,?)"))
		{
			int bookId = 1012;
			statement.setInt(1, bookId);
			
			String subjectName = "Operating System";
			statement.setString(2, subjectName);
			
			String bookName = "Operating System Concept's";
			statement.setString(3, bookName);
			
			String authorName = "Galvin";
			statement.setString(4, authorName);
			
			float price = 800;
			statement.setFloat(5, price);
			
			Date date = Date.valueOf("2013-10-29");
			statement.setDate(6, date);	
			
			int rowsAffected = statement.executeUpdate(  );
			System.out.println(rowsAffected+" row(s) affected");
		}
		catch (SQLException e) 
		{			
			e.printStackTrace();
		}
		
	}
}
