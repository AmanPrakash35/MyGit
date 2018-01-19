package test;

import java.sql.Connection;
import java.sql.Date;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import pojo.Book;
import utils.DbUtils;

public class Program {
	public static void main(String[] args) {
		try( Connection connection = DbUtils.getConnection();
			Statement statement = connection.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE, ResultSet.CONCUR_UPDATABLE);)
		{
			String sql = "select * from BookTable";
			try( ResultSet rs = statement.executeQuery(sql); )
			{				
				
				/*while( rs.next())
				{
					int bookId = rs.getInt("book_id");
					if( bookId == 1006 )
					{
						rs.updateString("book_name", "The C Plus Plus Programming Language");
						rs.updateRow();
						break;
					}
				}*/	
				/*while( rs.next())
				{
					int bookId = rs.getInt("book_id");
					if( bookId == 1006 )
					{						
						rs.deleteRow();
						break;
					}
				}*/
			rs.moveToInsertRow(); // moves cursor to the insert row
		       rs.updateInt("book_id", 1006);
		       rs.updateString("book_name", "The C++ Prog Language");
		       rs.updateString("subject_name", "C++");
		       rs.updateString("author_name", "Bjarne Stroustrup");
		       rs.updateFloat("price", 4000);
		       rs.updateDate("publish_date", Date.valueOf("1989-01-21"));
		       rs.insertRow();
		       rs.moveToCurrentRow();
			}
		}
		catch (SQLException e) 
		{			
			e.printStackTrace();
		}
		
	}
}
