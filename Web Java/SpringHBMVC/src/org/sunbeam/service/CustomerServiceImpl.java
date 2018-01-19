package org.sunbeam.service;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.sunbeam.dao.CustomerDao;
import org.sunbeam.pojo.Customer;
@Service
@Transactional
public class CustomerServiceImpl implements  CustomerService
{
	@Autowired
	CustomerDao dao;
	public CustomerServiceImpl() {
		
	}
	@Override
	public String insertCustomer(Customer customer) {
		Integer id =  this.dao.insertCustomer(customer);
		if( id != null )
			return "success";
		return "fail";
	}
	@Override
	public Customer validateCustomer(String email, String password) {		
		return dao.validateCustomer(email, password);
	}
}
