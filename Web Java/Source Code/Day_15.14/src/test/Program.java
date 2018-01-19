package test;

import java.sql.Connection;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.List;
import java.util.Scanner;

import dao.BookDao;
import pojo.Book;
import utils.DbUtils;

class BookDaoTest
{
	BookDao dao;
	public BookDaoTest() throws Exception 
	{		
		this.dao = new  BookDao( DbUtils.getConnection( ) );
		
	}
	static Scanner sc = new Scanner(System.in);
	public static void acceptRecord( Book book )
	{
		System.out.print("Book id	:	");
		book.setBookId(sc.nextInt());
		System.out.print("Subject name	:	");
		sc.nextLine();
		book.setSubjectName(sc.nextLine());
		System.out.print("Book Name	:");
		book.setBookName(sc.nextLine());
		System.out.print("Author Name	:	");
		book.setAuthorName(sc.nextLine());
		System.out.print("Price	:	");
		book.setPrice(sc.nextFloat());
		System.out.print("Publish Date	:	");
		sc.nextLine();
		book.setPublishDate(Date.valueOf(sc.nextLine()));
	}
	public void insertBook()throws Exception
	{
		Book book = new  Book();
		BookDaoTest.acceptRecord(book);
		this.dao.insertBook(book);
	}
	public void updateBook()throws Exception
	{
		Book book = new  Book();
		BookDaoTest.acceptRecord(book);
		this.dao.updateBook(book);
	}
	public void deleteBook()throws Exception
	{
		System.out.print("Enter book id	:	");
		this.dao.deleteBook(sc.nextInt());
	}
	public void printBookDetails()throws Exception
	{
		List<Book> bookList = this.dao.getBookList();
		bookList.forEach(System.out::println);
	}
	public void closeResources()throws Exception
	{
		this.dao.close();
	}
	public static int menuList()
	{
		System.out.println("0.Exit");
		System.out.println("1.Insert Book");
		System.out.println("2.Update Book");
		System.out.println("3.Delete Book");
		System.out.println("4.Print Book Details");
		System.out.print("Enter choice	:	");
		return sc.nextInt();
	}
}
public class Program {
	public static void main(String[] args) {		
		try
		{
			int choice;
			BookDaoTest test = new BookDaoTest();
			while( ( choice = BookDaoTest.menuList( ) ) != 0 )
			{
				switch( choice )
				{
				case 1:
					test.insertBook();
					break;
				case 2:
					test.updateBook();
					break;
				case 3:
					test.deleteBook();
					break;
				case 4:
					test.printBookDetails();
					break;
				}
			}
			test.closeResources();
		}
		catch(Exception ex )
		{
			ex.printStackTrace();
		}		
	}
}
