package dao;

import java.io.Closeable;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Properties;

import pojo.User;

public class UserDao implements Closeable
{
	private  Connection connection;
	private PreparedStatement insertStatement;
	private PreparedStatement selectStatement;
	public UserDao() throws Exception
	{		
		Class.forName("com.mysql.jdbc.Driver");
		this.connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/dacdb","root","manager");
		this.insertStatement = this.connection.prepareStatement("insert into UsersTable values(?,?,?,?)");
		this.selectStatement = this.connection.prepareStatement("select * from UsersTable where name=? and password=?");
	}
	public UserDao( Properties p) throws Exception
	{		
		Class.forName(p.getProperty("DRIVER"));
		this.connection = DriverManager.getConnection(p.getProperty("URL"), p.getProperty("USER"),p.getProperty("PASSWORD"));
		this.insertStatement = this.connection.prepareStatement("insert into UsersTable values(?,?,?,?)");
		this.selectStatement = this.connection.prepareStatement("select * from UsersTable where name=? and password=?");
	}
	public int insertUser( User user )throws SQLException
	{
		this.insertStatement.setString(1, user.getName());
		this.insertStatement.setString(2, user.getPassword());
		this.insertStatement.setString(3, user.getEmail());
		this.insertStatement.setString(4, user.getMobileNumber());
		return this.insertStatement.executeUpdate();
	}
	public User getUserDetails( String name, String password )throws SQLException
	{
		this.selectStatement.setString(1, name);
		this.selectStatement.setString(2, password);
		try( ResultSet rs = this.selectStatement.executeQuery())
		{
			if( rs.next())
				return new User(rs.getString(1), rs.getString(2), rs.getString(3), rs.getString(4));
		}
		return null;
	}
	@Override
	public void close() throws IOException 
	{
		try
		{
			this.insertStatement.close();
			this.selectStatement.close();
			this.connection.close();
		}
		catch (SQLException e) 
		{
			throw new IOException(e);
		}
	}
}
