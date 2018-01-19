package test;

import java.io.InputStream;
import java.sql.*;
import java.util.Properties;

import pojo.Book;
import utils.DbUtil;

public class Program {

	public static void main(String[] args) {

		try (Connection connection = DbUtil.getConnection(); Statement statement = connection.createStatement();) {
			String sql = "select * from BookTable";
			try (ResultSet rs = statement.executeQuery(sql);) {
				while (rs.next()) {
					Book book = new Book(rs.getInt("book_id"), rs.getString("subject_name"), rs.getString("book_name"),
							rs.getString("author_name"), rs.getFloat("price"), rs.getDate("publish_date"));
					System.out.println(book.toString());
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		} 
	}
}
