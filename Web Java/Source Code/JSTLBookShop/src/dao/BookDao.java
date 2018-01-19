package dao;

import java.io.Closeable;
import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

import pojo.Book;
import utils.DBUtils;

public class BookDao implements Closeable
{
	private Connection connection;
	private PreparedStatement statement1;
	private PreparedStatement statement2;
	private PreparedStatement statement3;
	public BookDao() throws SQLException{
		this(DBUtils.getConnection());
	}
	public BookDao(Connection connection ) throws SQLException{
		this.connection = connection;
		this.statement1 = this.connection.prepareStatement("select distinct subject_name from BookTable");
		this.statement2 = this.connection.prepareStatement("select * from BookTable where subject_name=?");
		this.statement3 = this.connection.prepareStatement("select * from BookTable where book_id=?");
	}
	public Set<String> getSubjects()throws SQLException
	{
		Set<String> subjects = new TreeSet<>();
		try( ResultSet rs =  this.statement1.executeQuery())
		{
			while( rs.next())
			{
				subjects.add(rs.getString(1));
			}
		}
		return subjects;
	}
	public List<Book> getBooks( String subjecct )throws SQLException 
	{
		List<Book> bookList = new ArrayList<>();
		this.statement2.setString(1, subjecct);
		try( ResultSet rs = this.statement2.executeQuery())
		{		
			while( rs.next())
			{
				Book book = new Book(rs.getInt(1), rs.getString(2),rs.getString(3),rs.getString(4),rs.getFloat(5), rs.getDate(6));
				bookList.add(book);
			}
		}
		return bookList;
	}
	public Book getBook( int bookId )throws SQLException 
	{		
		this.statement3.setInt(1, bookId);
		try( ResultSet rs = this.statement3.executeQuery())
		{		
			if( rs.next())			
				return new Book(rs.getInt(1), rs.getString(2),rs.getString(3),rs.getString(4),rs.getFloat(5), rs.getDate(6));				
		}
		return null;
	}
	@Override
	public void close() throws IOException {
		
	}
}
