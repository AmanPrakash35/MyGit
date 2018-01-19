package org.sunbeam.controller;

import javax.servlet.http.HttpSession;


import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.sunbeam.pojo.Customer;
import org.sunbeam.service.CustomerService;

@Controller
@RequestMapping("cust")
public class CustomerController
{
	@Autowired
	private CustomerService service;
	
	//@RequestMapping(value="/register", method=RequestMethod.GET)
	@GetMapping("/register")
	public String showRegistrationForm( Customer customer )
	{				
		return "/user/Registration";
	}
	@PostMapping("/register")	
	public String registerUser( Customer customer )
	{	
		String regStatus = service.insertCustomer(customer);
		if( regStatus.equals("success"))
			return "redirect:/cust/login";
		return "/user/Registration";
	}
	@GetMapping("/login")	
	public String showLoginForm( Customer customer )
	{
		System.out.println("showLoginForm");
		return "/user/Login";
	}
	/*@PostMapping("/login")
	public String validateCustomer( Customer customer, HttpSession session )
	{		
		Customer cust = service.validateCustomer(customer.getEmail(), customer.getPassword());
		System.out.println(cust);	
		if( cust != null )
		{
			session.setAttribute("CustDetails", cust);
			return "redirect:/cust/details";
		}		
		return "/user/Login";
	}*/
	@GetMapping("/details")
	public String showDetailsForm()
	{
		return "/customer/Details";
	}
}
