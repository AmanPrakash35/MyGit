package dao;

import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

import pojo.Book;
import utils.HBUtils;

public class BookDao
{
	static SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-YYYY");
	SessionFactory sessionFactory;	
	public BookDao() {
		sessionFactory = HBUtils.getSessionFactory();
	}
	public void saveBook_1(  )throws Exception
	{
		Session session = sessionFactory.getCurrentSession();
		Transaction transaction = null;		
		try
		{
			transaction = session.beginTransaction();
			
			/*Book book = new Book(null,"The C Prog. Language","Dennis Ritchie",550.45f,sdf.parse("12-10-2014"));
			Integer bookId = (Integer) session.save(book);	//If id is null then do not throw exception
			System.out.println("Book id	:	"+bookId);*/
			
			/*Book book = new Book(1,"The C++ Prog. Language","Bjarne Stroustrup",650.45f,sdf.parse("29-01-2013"));
			Integer bookId = (Integer) session.save(book);	//If id is non null then do not throw exception : id gets ignored
			System.out.println("Book id	:	"+bookId);*/
			
			/*Book book = new Book(5,"Java Certification","Khalid Mughal",600.45f,sdf.parse("29-01-2011"));
			Integer bookId = (Integer) session.save(book);	//Ok: if id does not exist then it ignores id and generate implicitly. 
			System.out.println("Book id	:	"+bookId);*/
			
			transaction.commit();
			
			/*Book book = new Book(1,"Java Certification","Khalid Mughal",600.45f,sdf.parse("29-01-2011"));
			Integer bookId = (Integer) session.save(book);	//java.lang.IllegalStateException
			System.out.println("Book id	:	"+bookId);*/
		}
		catch (Exception e) {
			if( transaction != null )
				transaction.rollback();
			throw e;
		}		
	}
	public void saveBook_2(  )throws Exception
	{
		Session session = sessionFactory.openSession();
		Transaction transaction = null;		
		try
		{
			transaction = session.beginTransaction();		
			
			transaction.commit();
			
			Book book = new Book(1,"Java Certification","Khalid Mughal",600.45f,sdf.parse("29-01-2011"));
			Integer bookId = (Integer) session.save(book);
			System.out.println("Book id	:	"+bookId);		
			
		}
		catch (Exception e) {
			if( transaction != null )
				transaction.rollback();
			throw e;
		}
		finally
		{	
			if(session != null )
			{
				System.out.println("Press any key to continue...");
				System.in.read();
				
				session.close();	//No Problem: It will flush the state of object into db
			}
		}
	}
	public void saveBook_3(  )throws Exception
	{
		Session session = sessionFactory.openSession();
		Transaction transaction = null;		
		try
		{
			transaction = session.beginTransaction();		
			
			transaction.commit();
		
			session.close();
			
			Book book = new Book(5,"CLR Via C#","Jeffery Ritcher",850.45f,sdf.parse("29-01-2017"));
			Integer bookId = (Integer) session.save(book);	//java.lang.IllegalStateException
			System.out.println("Book id	:	"+bookId);		
			
		}
		catch (Exception e) {
			if( transaction != null )
				transaction.rollback();
			throw e;
		}		
	}
	public void persistBook_1(  )throws Exception
	{
		Session session = sessionFactory.getCurrentSession();
		Transaction transaction = null;		
		try
		{
			transaction = session.beginTransaction();
			
			/*Book book = new Book(null,"The C Prog. Language","Dennis Ritchie",550.45f,sdf.parse("12-10-2014"));
			session.persist(book);	//OK */
			
			/*Book book = new Book(1,"The C++ Prog. Language","Bjarne Stroustrup",650.45f,sdf.parse("29-01-2013"));
			session.persist(book);	//If id is already exist : PersistentObjectException*/			
			
			Book book = new Book(2,"The C++ Prog. Language","Bjarne Stroustrup",650.45f,sdf.parse("29-01-2013"));
			session.persist(book); //PersistentObjectException: detached entity passed to persist
			
			transaction.commit();
			
			/*Book book = new Book(3,"Java Certification","Khalid Mughal",600.45f,sdf.parse("29-01-2011"));
			session.persist(book);	//java.lang.IllegalStateException */			
		}
		catch (Exception e) {
			if( transaction != null )
				transaction.rollback();
			throw e;
		}		
	}
	public void persistBook_2(  )throws Exception
	{
		Session session = sessionFactory.openSession();
		Transaction transaction = null;		
		try
		{
			transaction = session.beginTransaction();
			
			transaction.commit();
			
			Book book = new Book(null,"The C Prog. Language","Dennis Ritchie",550.45f,sdf.parse("12-10-2014"));
			session.persist(book);	//OK : But state will not be reflected 						
		}
		catch (Exception e) {
			if( transaction != null )
				transaction.rollback();
			throw e;
		}		
		finally
		{
			if( session != null )
			{
				session.close();
			}
		}
	}
	public void persistBook_3(  )throws Exception
	{
		Session session = sessionFactory.openSession();
		Transaction transaction = null;		
		try
		{
			transaction = session.beginTransaction();
			
			transaction.commit();
			
			session.close();
			
			Book book = new Book(null,"The C Prog. Language","Dennis Ritchie",550.45f,sdf.parse("12-10-2014"));
			session.persist(book);	//java.lang.IllegalStateException 						
		}
		catch (Exception e) {
			if( transaction != null )
				transaction.rollback();
			throw e;
		}		
	}	
	public void save_or_updateBook(  )throws Exception
	{
		Session session = sessionFactory.getCurrentSession();
		Transaction transaction = null;		
		try
		{
			transaction = session.beginTransaction();			
			
			/*Book book = new Book(null,"The C Prog. Language","Dennis Ritchie",550.45f,sdf.parse("12-10-2014"));
			session.saveOrUpdate(book);	//OK */			
			
			/*Book book = new Book(1,"The C++ Prog. Language","BJarne Stroustrup",550.45f,sdf.parse("12-10-2014"));
			session.saveOrUpdate(book);	//OK : Update */
			
			Book book = new Book(2,"The C++ Prog. Language","BJarne Stroustrup",550.45f,sdf.parse("12-10-2014"));
			session.saveOrUpdate(book);	//StaleStateException
			transaction.commit();
		}
		catch (Exception e) {
			if( transaction != null )
				transaction.rollback();
			throw e;
		}		
	}
	
	public Book getBookDetails( int bookId )
	{
		Book book = null;
		Session session = sessionFactory.getCurrentSession();
		Transaction transaction = session.beginTransaction();
		try
		{
			book = session.get(Book.class, bookId);			
			transaction.commit();
		}
		catch( HibernateException ex )
		{
			if( transaction != null )
				transaction.rollback();
			throw ex;
		}
		return book;
	}
	
	public List<Book> getAllBooks()
	{
		List<Book> bookList = null;
		Session session = sessionFactory.getCurrentSession();
		Transaction transaction = session.beginTransaction();
		try
		{
			String hql = "select b from Book b";
			bookList = session.createQuery(hql, Book.class).getResultList();
			transaction.commit();
		}
		catch( HibernateException ex)
		{
			if( transaction != null )
				transaction.rollback();
			throw ex;
		}
		return bookList;
	}
	
	public List<Book> getBooksByCriteria( String authorName, Date publishDate )
	{
		List<Book> bookList = null;
		Session session = sessionFactory.getCurrentSession();
		Transaction transaction = session.beginTransaction();
		try
		{
			String hql = "select b from Book b where b.author=:author and b.publishDate < :publishDate";
			Query<Book> query = session.createQuery(hql, Book.class);
			query.setParameter("author", authorName);
			query.setParameter("publishDate", publishDate);
			bookList = query.getResultList();
			transaction.commit();
		}
		catch( HibernateException ex)
		{
			if( transaction != null )
				transaction.rollback();
			throw ex;
		}
		return bookList;
	}
	public int applyDiscount( Date publishDate, double amount )
	{
		int updateCount  = 0;
		Session session = sessionFactory.getCurrentSession();
		Transaction transaction = session.beginTransaction();
		try
		{
			String hql = "update Book b set b.price = b.price - :amount where b.publishDate < :publishDate";
			Query<Book> query = session.createQuery(hql);			
			query.setParameter("amount", amount);
			query.setParameter("publishDate", publishDate);
			updateCount = query.executeUpdate();
			transaction.commit();
		}
		catch( HibernateException ex)
		{
			if( transaction != null )
				transaction.rollback();
			throw ex;
		}
		return updateCount;
	}
	public List<Book> deleteBooks( Date publishDate )
	{
		List<Book> bookList = null;
		Session session = sessionFactory.getCurrentSession();
		Transaction transaction = session.beginTransaction();
		try
		{
			String hql = "select b from Book b where b.publishDate > :publishDate";
			Query<Book> query = session.createQuery(hql,Book.class);			
			query.setParameter("publishDate", publishDate);			
			bookList = query.getResultList();
			for (Book book : bookList) 
			{
				session.delete(book);
			}
			session.clear();
			transaction.commit();
		}
		catch( HibernateException ex)
		{
			if( transaction != null )
				transaction.rollback();
			throw ex;
		}	
		return bookList;
	}
	public void merge()throws Exception
	{
		Session session = sessionFactory.getCurrentSession();		
		Transaction transaction = null;
		Integer bookId;
		try
		{
			/*Book book = new Book("Let Us C", "Yashvant Kanetkar", 500, new SimpleDateFormat("dd-MM-YYYY").parse("12-01-2015"));
			book.setBookId(100);
			
			transaction = session.beginTransaction();
			Book b1 =  (Book) session.merge(book);
			System.out.println(b1.getBookId());*/
			transaction.commit();
			
		}
		catch (HibernateException e) {
			if( transaction != null )
				transaction.rollback();
			throw e;
		}
	}
}
