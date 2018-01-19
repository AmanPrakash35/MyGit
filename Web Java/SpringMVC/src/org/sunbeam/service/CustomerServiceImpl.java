package org.sunbeam.service;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.springframework.stereotype.Service;
import org.sunbeam.Customer.Customer;

@Service
public class CustomerServiceImpl implements  CustomerService
{
	private Map<String, Customer> map;
	public CustomerServiceImpl() {
		this.map = new HashMap<String, Customer>();
		this.map.put("abc", new Customer());
		this.map.put("xyz", new Customer());
	}
	@Override
	public List<Customer> listCustomers() 
	{
		return new ArrayList<Customer>( map.values());
	}
}
