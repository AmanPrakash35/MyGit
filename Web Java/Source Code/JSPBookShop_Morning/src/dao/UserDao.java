package dao;

import java.io.Closeable;
import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import pojo.User;
import utils.DBUtils;
public class UserDao implements Closeable
{
	private Connection connection;
	private PreparedStatement insertStatement;
	private PreparedStatement selectStatement;
	public UserDao()throws SQLException {
		this(DBUtils.getConnection());
	}
	public UserDao(Connection connection ) throws SQLException{
		this.connection = connection;
		this.insertStatement = connection.prepareStatement("insert into UserTable values(?,?,?,?,?)");
		this.selectStatement = connection.prepareStatement("select * from UserTable where user_name=? and password=?");
	}
	public int insertUser( User user )throws SQLException
	{
		this.insertStatement.setString(1, user.getUserName());
		this.insertStatement.setString(2, user.getPassword());
		this.insertStatement.setString(3, user.getEmail());
		this.insertStatement.setString(4, user.getContactNumber());
		this.insertStatement.setDate(5, user.getAccountCreationDate());
		return this.insertStatement.executeUpdate();
	}
	public User authenticateUser( String userName, String password )throws SQLException
	{
		this.selectStatement.setString(1, userName);
		this.selectStatement.setString(2, password );
		try( ResultSet rs = this.selectStatement.executeQuery();)
		{
			if( rs.next())
				return new User(rs.getString(1),rs.getString(2),rs.getString(3),rs.getString(4), rs.getDate(5));
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
		catch( SQLException cause)
		{
			throw new IOException(cause);
		}
	}
}
