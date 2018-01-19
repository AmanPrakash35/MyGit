package org.sunbeam.dac.test;

import java.sql.CallableStatement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.JDBCType;
import java.sql.SQLException;
import java.sql.Statement;

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
			connection= DriverManager.getConnection(URL,USER,PASSWORD);
			connection.setAutoCommit(false);
			
			statement = connection.createStatement();
			
			String sql = "update AccountTable set balance = balance-5000 where acc_number = 1002";
			statement.executeUpdate(sql);
			
			String str = "123abc";
			int number = Integer.parseInt(str);
			
			sql = "update AccountTable set balance = balance + 5000 where acc_number = 1001";
			statement.executeUpdate(sql);
			
			connection.commit();
		}
		catch(Exception ex)
		{
			try 
			{
				connection.rollback();
				ex.printStackTrace();
			} catch (SQLException e) {				
				e.printStackTrace();
			}
		}
		finally
		{
			try {
				statement.close();
				connection.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
