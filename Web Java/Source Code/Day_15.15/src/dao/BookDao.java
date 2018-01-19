package dao;

import java.io.Closeable;
import java.io.IOException;
import java.sql.Connection;
import java.sql.CallableStatement;
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
	CallableStatement insertStatement;
	CallableStatement updateStatement;
	CallableStatement deleteStatement;
	CallableStatement selectStatement;
	public BookDao()throws SQLException
	{	
		this( DbUtils.getConnection());
	}	
	public BookDao( Connection connection )throws  SQLException
	{
		this.connection = connection;		
		this.insertStatement = this.connection.prepareCall("{call sp_insert_book(?,?,?,?,?,?)}"); 
		this.updateStatement = this.connection.prepareCall("{call sp_update_book(?,?,?,?,?,?)}");
		this.deleteStatement = this.connection.prepareCall("{call sp_delete_book(?)}");
		this.selectStatement = this.connection.prepareCall("{call sp_get_books( )}");
	}	
	public boolean insertBook( Book book )throws SQLException
	{		
		this.insertStatement.setInt(1, book.getBookId());
		this.insertStatement.setString(2, book.getSubjectName());
		this.insertStatement.setString(3, book.getBookName());
		this.insertStatement.setString(4, book.getAuthorName());
		this.insertStatement.setFloat(5, book.getPrice());
		this.insertStatement.setDate(6, book.getPublishDate());
		return this.insertStatement.execute();
	}
	public boolean updateBook( Book book )throws SQLException
	{				
		this.updateStatement.setString(1, book.getSubjectName());
		this.updateStatement.setString(2, book.getBookName());
		this.updateStatement.setString(3, book.getAuthorName());
		this.updateStatement.setFloat(4, book.getPrice());
		this.updateStatement.setDate(5, book.getPublishDate());
		this.updateStatement.setInt(6, book.getBookId());
		return this.updateStatement.execute();
	}	
	public boolean deleteBook( int bookId )throws SQLException
	{		
		this.deleteStatement.setInt(1, bookId);
		return this.deleteStatement.execute();
	}
	public List<Book> getBookList( )throws SQLException
	{		
		List<Book> bookList = new ArrayList<Book>();
		this.selectStatement.execute();
		try( ResultSet rs = this.selectStatement.getResultSet())
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
