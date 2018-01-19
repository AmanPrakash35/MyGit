package org.sunbeam.dao;

import org.hibernate.SessionFactory;
import org.hibernate.query.Query;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;
import org.sunbeam.pojo.Customer;

@Repository
public class CustomerDaoImplementation implements CustomerDao 
{
	@Autowired
	private SessionFactory sessionFactory;
	
	@Override
	public Integer insertCustomer(Customer customer) 
	{
		return (Integer) this.sessionFactory.getCurrentSession().save(customer);
	}
	@Override
	public Customer validateCustomer(String email, String password) {
		String hql = "select c from Customer c where c.email=:Email and c.password=:Password";
		Query<Customer> query = this.sessionFactory.getCurrentSession().createQuery(hql, Customer.class);
		query.setParameter("Email", email);
		query.setParameter("Password", password);		
		Customer customer= query.getSingleResult();		
		return customer;
		/*return this.sessionFactory.getCurrentSession().createQuery("select c from Customer c where c.email=:Email and c.password=:Password", Customer.class).setParameter("Email", email).setParameter("Password", password).getSingleResult();*/
	}
}
