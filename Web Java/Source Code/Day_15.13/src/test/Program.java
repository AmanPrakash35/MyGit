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
			PreparedStatement statement = connection.prepareStatement("delete from BookTable where book_id=?"))
		{
			int bookId = 1012;
			statement.setInt(1, bookId);
			
			int rowsAffected = statement.executeUpdate(  );
			System.out.println(rowsAffected+" row(s) affected");
		}
		catch (SQLException e) 
		{			
			e.printStackTrace();
		}		
	}
}
