package org.sunbeam.dac.test;

import java.sql.CallableStatement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.JDBCType;

public class Program 
{
	public static final String URL = "jdbc:mysql://localhost:3306/dacdb";
	public static final String USER = "root";
	public static final String PASSWORD = "manager";
	public static void main(String[] args) 
	{
		Connection connection = null;
		CallableStatement statement = null;
		try
		{
			connection= DriverManager.getConnection(URL,USER,PASSWORD);
			
			statement = connection.prepareCall("{call sp_update_account(?,?,?,?,?)}");
			
			statement.setInt(1, 1001);
			statement.setFloat(2, 5000);
			statement.setInt(3, 1002);
			
			statement.registerOutParameter(4, JDBCType.FLOAT);
			statement.registerOutParameter(5, JDBCType.FLOAT);
			
			boolean status = statement.execute();
			
			float srcBalance = statement.getFloat(4);
			System.out.println("Source Balance	:	"+srcBalance);
			
			float destBalance = statement.getFloat(5);
			System.out.println("Source Balance	:	"+destBalance);
		}
		catch(Exception ex)
		{
			ex.printStackTrace();
		}
		finally
		{
			
		}
	}
}
