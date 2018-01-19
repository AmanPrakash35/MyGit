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
			
			statement = connection.prepareCall("{?=call fn_update_account(?,?,?)}");
			
			statement.setInt(2, 1001);
			statement.setFloat(3, 5000);
			statement.setInt(4, 1002);
			
			statement.registerOutParameter(1, JDBCType.FLOAT);			
			
			statement.execute();
			
			float srcBalance = statement.getFloat(1);
			System.out.println("Source Balance	:	"+srcBalance);
			
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
