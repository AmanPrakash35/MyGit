package org.sunbeam.controller;

import java.time.LocalDate;
import java.util.Date;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class HelloController
{
	public HelloController() {
		System.out.println("Inside ctor of "+this.getClass().getSimpleName());
	}
	
	@PostConstruct
	public void init( )
	{	}
	
	@RequestMapping(value="/hello1")
	public String sayHello1()
	{
		return "Welcome";
	}	
	
	@RequestMapping(value="/hello2")
	public ModelAndView sayHello2()	{		
		
		ModelAndView view  = new  ModelAndView("Welcome", "date", new Date());
		return view;
	}	

	@RequestMapping(value="/hello3")
	public String sayHello3( Model map )
	{		
		map.addAttribute("Name", "Sandeep");
		map.addAttribute("Empid", 33);
		map.addAttribute("JoinDate", new Date());
		return "Welcome";
	}	
	
	@RequestMapping(value="/hello4")
	public String sayHello4( @RequestParam String name, @RequestParam int empid, Model map )
	{		
		map.addAttribute("Name", name);
		map.addAttribute("Empid", empid);
		
		return "Welcome";
	}
	
	@RequestMapping(value="/hello5/{name}/{empid}")
	public String sayHello5( @PathVariable String name, @PathVariable int empid, Model map )
	{		
		map.addAttribute("Name", name);
		map.addAttribute("Empid", empid);
		
		return "Welcome";
	}
	@PreDestroy
	public void destroy( )
	{	}
}
