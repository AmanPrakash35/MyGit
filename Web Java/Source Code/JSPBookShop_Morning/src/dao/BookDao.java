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

import javax.servlet.ServletException;

import pojo.Book;
import utils.DBUtils;

public class BookDao implements Closeable {
	private Connection connection;
	private PreparedStatement distinctSubjectStatement;
	private PreparedStatement booksStatement;
	private PreparedStatement bookStatement;
	public BookDao() throws SQLException{
		this(DBUtils.getConnection());
	}
	public BookDao(Connection connection)throws SQLException
	{
		this.connection = connection;
		this.distinctSubjectStatement = this.connection.prepareStatement("select distinct subject_name from BookTable");
		this.booksStatement = this.connection.prepareStatement("select * from BookTable where subject_name=?");
		this.bookStatement = this.connection.prepareStatement("select * from BookTable where book_id=?");
	}
	public Set<String> getSubjects()throws SQLException
	{
		Set<String> books = new TreeSet<>();
		try( ResultSet rs = this.distinctSubjectStatement.executeQuery();)
		{
			while( rs.next())
				books.add(rs.getString(1));
		}
		return books;
	}
	public List<Book> getBooksBySubject(String subject )throws SQLException
	{
		List<Book> bookList = new ArrayList<Book>( );
		this.booksStatement.setString(1, subject);
		try( ResultSet rs = this.booksStatement.executeQuery())
		{
			while( rs.next())
			{
				Book book =  new  Book( rs.getInt(1), rs.getString( 2 ), rs.getString(3), rs.getString(4),rs.getFloat(5),rs.getDate(6));
				bookList.add(book);
			}
		}
		return bookList;
	}
	public Book getBook( int bookId )throws SQLException
	{
		this.bookStatement.setInt(1, bookId);
		try( ResultSet rs = this.bookStatement.executeQuery())
		{
			if( rs.next())
			{
				Book book =  new  Book( rs.getInt(1), rs.getString( 2 ), rs.getString(3), rs.getString(4),rs.getFloat(5),rs.getDate(6));
				return book;
			}
		}
		return null;
	}
	
	@Override
	public void close() throws IOException {
		try
		{
			this.distinctSubjectStatement.close();
			this.connection.close();
		}
		catch(SQLException ex)
		{
			throw new IOException(ex);
		}
	}
}
