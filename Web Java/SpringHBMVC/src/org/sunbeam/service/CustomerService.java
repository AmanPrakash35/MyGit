package org.sunbeam.service;

import java.util.List;

import org.sunbeam.pojo.Customer;

public interface CustomerService
{
	String insertCustomer( Customer customer );
	
	Customer validateCustomer( String email, String password );
}
