package test;

import org.springframework.context.support.ClassPathXmlApplicationContext;

import dependant.Atm;

public class Program 
{
	public static void main(String[] args) 
	{
		try( ClassPathXmlApplicationContext context = new  ClassPathXmlApplicationContext("Spring-Config.xml") )
		{
			System.out.println("Spring Container is Started...");
			Atm atm1 = context.getBean("myAtm", Atm.class);
			atm1.deposit(500);
			
			Atm atm2 = context.getBean("myAtm", Atm.class);
			atm2.deposit(500);
			
			System.out.println(atm1 == atm2 );
		}
	}

}
