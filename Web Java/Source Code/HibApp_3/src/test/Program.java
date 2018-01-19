package test;

import java.text.SimpleDateFormat;

import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;

import dto.Book;
import utils.HBUtils;

public class Program 
{
	static SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-YYYY");
	public static void main(String[] args) 
	{
		SessionFactory factory = HBUtils.getSessionFactory();
		Session session = factory.openSession();
		Transaction transaction = null;
		try
		{
			transaction = session.beginTransaction();
			Book book = new Book("Let Us C", "Yashwant Kanetkar", 550.50f, sdf.parse("12-7-2015"));
			Integer bookId =  (Integer) session.save(book);
			System.out.println("Book id "+bookId);
			transaction.commit();
		}
		catch( Exception ex )
		{
			if( transaction != null )
				transaction.rollback();
			ex.printStackTrace();			
		}
		finally
		{
			session.close();				
		}
		factory.close();
	}
}
