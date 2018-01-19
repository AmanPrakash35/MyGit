package org.sunbeam.controller;

import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.sunbeam.pojo.Customer;
import org.sunbeam.service.CustomerService;

@Controller
@RequestMapping("cust")
public class CustomerController 
{
	@Autowired
	private CustomerService service;;
	
	@GetMapping("/register")
	public String showRegistrationForm( Customer customer )
	{
		return "/user/Registration";
	}
	@PostMapping("/register")
	public String insertUser( Customer customer )
	{
		String regStatus = service.insertCustomer(customer);
		if( regStatus.equals("success"))
			return "redirect:/cust/login";
		return "/user/Registration";
	}
	@GetMapping("/login")
	public String showLoginForm(Customer customer )
	{
		return "/user/Login";
	}
	@PostMapping("/login")
	public String validateCustomer(Customer customer, HttpSession session )
	{
		Customer details = service.validateCustomer(customer.getEmail(), customer.getPassword());
		System.out.println(details);
		if(details != null )
		{
			session.setAttribute("CustDetails", details);
			return "redirect:/cust/details";
		}
		return "/user/Login";
	}
	@RequestMapping("/details")
	public String showDetailsForm( )
	{
		return "/customer/Details";
	}
	@RequestMapping("/logout")
	public String showLogoutForm( HttpSession session )
	{
		System.out.println("Logout");
		session.invalidate();
		return "/customer/Logout";
	}
}
