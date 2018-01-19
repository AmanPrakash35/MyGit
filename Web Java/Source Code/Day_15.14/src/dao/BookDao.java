package dao;

import java.io.Closeable;
import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

import pojo.Book;
import utils.DbUtils;

public class BookDao  implements Closeable
{	
	private Connection connection;
	PreparedStatement insertStatement;
	PreparedStatement updateStatement;
	PreparedStatement deleteStatement;
	PreparedStatement selectStatement;
	public BookDao()throws SQLException
	{	
		this( DbUtils.getConnection());
	}	
	public BookDao( Connection connection )throws  SQLException
	{
		this.connection = connection;
		this.insertStatement = this.connection.prepareStatement("insert into BookTable values(?,?,?,?,?,?)");
		this.updateStatement = this.connection.prepareStatement("update BookTable set subject_name=?,book_name=?,author_name=?,price=?,publish_date=? where book_id=?");
		this.deleteStatement = this.connection.prepareStatement("delete from BookTable where book_id=?");
		this.selectStatement = this.connection.prepareStatement("select * from BookTable");
	}	
	public int insertBook( Book book )throws SQLException
	{		
		this.insertStatement.setInt(1, book.getBookId());
		this.insertStatement.setString(2, book.getSubjectName());
		this.insertStatement.setString(3, book.getBookName());
		this.insertStatement.setString(4, book.getAuthorName());
		this.insertStatement.setFloat(5, book.getPrice());
		this.insertStatement.setDate(6, book.getPublishDate());
		return this.insertStatement.executeUpdate();
	}
	public int updateBook( Book book )throws SQLException
	{				
		this.updateStatement.setString(1, book.getSubjectName());
		this.updateStatement.setString(2, book.getBookName());
		this.updateStatement.setString(3, book.getAuthorName());
		this.updateStatement.setFloat(4, book.getPrice());
		this.updateStatement.setDate(5, book.getPublishDate());
		this.updateStatement.setInt(6, book.getBookId());
		return this.updateStatement.executeUpdate();
	}	
	public int deleteBook( int bookId )throws SQLException
	{		
		this.deleteStatement.setInt(1, bookId);
		return this.deleteStatement.executeUpdate();
	}
	public List<Book> getBookList( )throws SQLException
	{		
		List<Book> bookList = new ArrayList<Book>();
		try( ResultSet rs = this.selectStatement.executeQuery())
		{
			while( rs.next() )
			{
				Book book = new Book(rs.getInt("book_id"),rs.getString("subject_name"),rs.getString("book_name"),rs.getString("author_name"),rs.getFloat("price"),rs.getDate("publish_date"));
				bookList.add(book);
			}
		}
		return bookList;
	}	
	@Override
	public void close() throws IOException{
		try
		{
			this.insertStatement.close();
			this.updateStatement.close();
			this.deleteStatement.close();
			this.selectStatement.close();
			this.connection.close();
		}
		catch( SQLException cause)
		{
			throw new IOException(cause);
		}
	}
}
