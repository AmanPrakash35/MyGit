package test;

import java.io.InputStream;
import java.sql.*;
import java.util.Properties;

import pojo.Book;
import utils.DbUtil;

public class Program {

	public static void main(String[] args) {
		try (Connection connection = DbUtil.getConnection(); 
				Statement statement = connection.createStatement();)
		{
			//String sql = "insert into BookTable values(1003,'C','The C Programming Language','Dennis Ritchie',500.45,'1983-07-12')";
			//String sql = "update BookTable set subject_name='C', book_name='The C Programming Language',author_name='Dennis Ritchie',price=340.45,publish_date='1983-01-26' where book_id=1003";
			String sql = "delete from BookTable where book_id=1003";
			int rowsAffected = statement.executeUpdate(sql);
			System.out.println(rowsAffected+" row(s) affected");
		} catch (Exception e) {
			e.printStackTrace();
		} 
	}
}
