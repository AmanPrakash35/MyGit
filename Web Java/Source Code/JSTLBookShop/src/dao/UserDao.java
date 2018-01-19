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
	private PreparedStatement statement1;	//Insert
	private PreparedStatement statement2;	//Select
	public UserDao()  throws SQLException {
		this( DBUtils.getConnection());
	}
	public UserDao(Connection connection ) throws SQLException{
		this.connection = connection;
		this.statement1 = this.connection.prepareStatement("insert into UsersTable values(?,?,?,?)");
		this.statement2 = this.connection.prepareStatement("select * from UsersTable where name=? and password=?");
	}
	public int registerNewUser( User user )throws SQLException
	{
		this.statement1.setString(1,user.getName());
		this.statement1.setString(2,user.getPassword());
		this.statement1.setString(3, user.getEmail());
		this.statement1.setString(4, user.getMobileNumber());
		return this.statement1.executeUpdate();
	}
	public User authenticateUser( String name, String password )throws SQLException
	{
		this.statement2.setString(1, name);
		this.statement2.setString(2, password);
		try( ResultSet rs =  this.statement2.executeQuery())
		{
			if( rs.next())
				return new User(rs.getString(1),rs.getString(2),rs.getString(3),rs.getString(4));
		}
		return null;
	}	
	@Override
	public void close() throws IOException {
		try {
			this.statement1.close();
			this.statement2.close();
			this.connection.close();
		} catch (SQLException e) {
			throw new IOException(e);
		}
	}
}
