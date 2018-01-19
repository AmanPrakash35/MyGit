package dao;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;

import dto.Book;
import utils.HBUtils;

public class BookDao {
	SessionFactory factory;
	public BookDao()
	{
		this.factory = HBUtils.getSessionFactory();
	}
	public Integer insertBook( Book book )throws Exception
	{
		Integer bookId = null;
		/*Session session =  this.factory.openSession();
		Session session1 =  this.factory.openSession();*/
		
		Session session =  this.factory.getCurrentSession();		
		Transaction tx = null;
		try
		{
			tx = session.beginTransaction();
			bookId = (Integer) session.save(book);
			tx.commit();
		}
		catch(Exception ex )
		{
			if( tx != null )
				tx.rollback();
			throw ex;
		}
		/*finally
		{
			System.out.println(session.isOpen()+"	"+session.isConnected());
			session.close();
		}*/
		return bookId;
	}
}
