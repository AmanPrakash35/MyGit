package test;

import java.text.SimpleDateFormat;
import java.util.List;
import java.util.Scanner;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;

import dto.Department;
import dto.Employee;
import utils.HBUtils;

public class Program 
{
	static SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-YYYY");
/*	public static void main(String[] args) 
	{
		SessionFactory factory = HBUtils.getSessionFactory();		
		Session session = factory.getCurrentSession();
		Transaction tx = null;
		try(Scanner sc = new Scanner(System.in))
		{
			tx =  session.beginTransaction();
			
			System.out.print("Enter dept no	:	");
			int deptNumber = sc.nextInt();
			Department department = session.get(Department.class, deptNumber);
			List<Employee> employees = department.getEmpList();
			for (Employee employee : employees) {
				System.out.println(employee);
			}
			System.out.println(department);
			tx.commit();
		}
		catch( Exception ex )
		{
			if( tx != null )
				tx.rollback();
			ex.printStackTrace();
		}
		factory.close();
	}*/
	/*public static void main(String[] args) 
	{
		SessionFactory factory = HBUtils.getSessionFactory();		
		Session session = factory.getCurrentSession();
		Transaction tx = null;
		try(Scanner sc = new Scanner(System.in))
		{
			tx =  session.beginTransaction();
			
			Employee emp = new Employee(2011, "Sandeep", 45000);
			Department department = new Department(50, "Training", "Pune");
			emp.setDepartment(department);
			
			System.out.print("Enter emp id	:	");
			int empid = sc.nextInt();
			Employee  emp = session.get(Employee.class, empid);
			Department department = emp.getDepartment();
			
			System.out.println(emp + "	"+department );
			tx.commit();
		}
		catch( Exception ex )
		{
			if( tx != null )
				tx.rollback();
			ex.printStackTrace();
		}
		factory.close();
	}*/
	public static void main(String[] args) 
	{
		SessionFactory factory = HBUtils.getSessionFactory();		
		Session session = factory.getCurrentSession();
		Transaction tx = null;
		try(Scanner sc = new Scanner(System.in))
		{
			tx =  session.beginTransaction();
			
			Employee emp = new Employee(2012, "Prashant", 55000);
			Department department = new Department(60, "HR", "Mumbai");
			emp.setDepartment(department);
			
			session.persist(emp);
			
			tx.commit();
		}
		catch( Exception ex )
		{
			if( tx != null )
				tx.rollback();
			ex.printStackTrace();
		}
		factory.close();
	}
}
