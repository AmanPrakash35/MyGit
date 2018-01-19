package utils;

import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

import test.Program;

public class DbUtil
{
	static Properties prop;
	static
	{
		try 
		{
			InputStream inputStream = Program.class.getClassLoader().getResourceAsStream("Config.properties");
			prop = new Properties();
			prop.load(inputStream );
		} 
		catch (IOException e)
		{
			throw new RuntimeException(e);
		}
	}
	public static Connection getConnection( ) throws SQLException
	{
		return  DriverManager.getConnection(prop.getProperty("URL"), prop.getProperty("USER"), prop.getProperty("PASSWORD"));
	}
}
