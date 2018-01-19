package org.sunbeam.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.sunbeam.Customer.Customer;
import org.sunbeam.service.CustomerService;

@Controller
@RequestMapping("/cust")
public class CustomerController
{
	@Autowired
	private CustomerService service;
	
	@RequestMapping("/list")
	public String getCustomers( Model map)
	{
		List<Customer> list = service.listCustomers();
		map.addAttribute("custList", list);
		return "ListAll";
	}
}
