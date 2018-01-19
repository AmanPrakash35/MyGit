package dao;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

import pojo.User;
import utils.HBUtils;

public class UserDao
{
	private SessionFactory factory;
	public UserDao()  {
		this.factory = HBUtils.getSessionFactory();
	}	
	public void registerNewUser( User user )throws Exception
	{		
		Session session = this.factory.getCurrentSession();
		Transaction tx = null;
		try
		{
			tx = session.beginTransaction();
			session.persist(user);
			tx.commit();
		}
		catch( Exception ex )
		{
			if(tx != null )
				tx.rollback();
			throw ex;
		}
	}
	public User authenticateUser( String name, String password )throws Exception
	{
		User user = null;
		Session session = this.factory.getCurrentSession();
		Transaction tx = null;
		try
		{
			tx = session.beginTransaction();
			String hql = "select u from User u where u.name=:UserName and u.password=:Password";
			Query<User> query = session.createQuery(hql,User.class);
			query.setParameter("UserName", name);
			query.setParameter("Password", password);
			user = query.getSingleResult();
			tx.commit();
		}
		catch( Exception ex )
		{
			if(tx != null )
				tx.rollback();
			throw ex;
		}
		return user;
	}	
}
