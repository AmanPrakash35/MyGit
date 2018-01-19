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

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

import pojo.Book;
import utils.HBUtils;

public class BookDao
{
	private SessionFactory sessionFactory;
	public BookDao() {
		this.sessionFactory = HBUtils.getSessionFactory();
	}	
	public Set<String> getSubjects()throws Exception
	{
		Set<String> subjects = null;
		Session session = this.sessionFactory.getCurrentSession();
		Transaction tx = null;
		try
		{
			tx = session.beginTransaction();
			String hql = "select distinct b.subjectName from Book b";
			Query<String> query = session.createQuery(hql, String.class);
			List<String> subjectList = query.getResultList();
			if( subjectList != null )
				subjects = new TreeSet<>(subjectList);
			tx.commit();
		}
		catch(Exception ex)
		{
			if( tx != null )
				tx.rollback();
			throw ex;
		}
		return subjects;		
	}
	public List<Book> getBooks( String subject )throws SQLException 
	{
		List<Book> bookList = null;
		Session session = this.sessionFactory.getCurrentSession();
		Transaction tx = null;
		try
		{
			tx = session.beginTransaction();
			String hql = "select b from Book b where b.subjectName=:SubjectName";
			Query<Book> query = session.createQuery(hql, Book.class);
			query.setParameter("SubjectName", subject);
			bookList = query.getResultList();
			tx.commit();
		}
		catch(Exception ex)
		{
			if( tx != null )
				tx.rollback();
			throw ex;
		}
		return bookList;
	}
	public Book getBook( int bookId )throws Exception 
	{	
		Book book = null;
		Session session = this.sessionFactory.getCurrentSession();
		Transaction tx = null;
		try
		{
			tx = session.beginTransaction();
			book = session.get(Book.class, bookId);
			tx.commit();
		}
		catch(Exception ex)
		{
			if( tx != null )
				tx.rollback();
			throw ex;
		}
		return book;
	}
}
