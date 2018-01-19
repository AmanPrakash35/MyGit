package test;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import pojo.Book;
import utils.DbUtils;

public class Program {
	public static void main(String[] args) {
		try( Connection connection = DbUtils.getConnection();
			Statement statement = connection.createStatement(ResultSet.TYPE_FORWARD_ONLY, ResultSet.CONCUR_READ_ONLY);)
		{
			String sql = "select * from BookTable";
			try( ResultSet rs = statement.executeQuery(sql); )
			{
				while( rs.next())
				{
					Book book = new Book(rs.getInt("book_id"),rs.getString("subject_name"),rs.getString("book_name"),rs.getString("author_name"),rs.getFloat("price"),rs.getDate("publish_date"));
					System.out.println(book.toString());
				}
			}
		}
		catch (SQLException e) 
		{			
			e.printStackTrace();
		}
		
	}
}
