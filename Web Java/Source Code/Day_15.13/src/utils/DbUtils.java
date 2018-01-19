package utils;

import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

public class DbUtils 
{
	private static Properties prop;
	static
	{
		try
		{
			InputStream inputStream = DbUtils.class.getClassLoader().getResourceAsStream("Config.properties");
			prop = new Properties();
			prop.load(inputStream);
		}
		catch (IOException e) 
		{
			throw new RuntimeException("Invalid file name", e);
		}
		
	}
	public static Connection getConnection() throws SQLException
	{
		return DriverManager.getConnection( prop.getProperty("URL"), prop.getProperty("USER"),prop.getProperty("PASSWORD"));
	}
}
