package test;

import java.text.SimpleDateFormat;

import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;

import dao.BookDao;
import dto.Book;
import utils.HBUtils;

public class Program 
{
	static SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-YYYY");
	public static void main(String[] args) 
	{
		SessionFactory factory = HBUtils.getSessionFactory();		
		try
		{			
			Book book = new Book("Let Us C", "Yashwant Kanetkar", 550.50f, sdf.parse("12-7-2015"));
			BookDao dao = new BookDao();
			dao.insertBook(book);
		}
		catch( Exception ex )
		{		
			ex.printStackTrace();			
		}		
		factory.close();
	}
}
