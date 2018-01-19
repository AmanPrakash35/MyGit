package utils;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

import javax.servlet.ServletContext;

public class DBUtils
{
	private static ServletContext context;
	public static void setContext(ServletContext context) {
		DBUtils.context = context;
	}
	public static Connection getConnection()throws SQLException
	{
		return DriverManager.getConnection(context.getInitParameter("URL"),context.getInitParameter("USER"),context.getInitParameter("PASSWORD"));
	}
}
