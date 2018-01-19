package org.sunbeam.dac.test;

import java.lang.annotation.Annotation;
import java.lang.annotation.ElementType;
import java.lang.annotation.Repeatable;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;
import java.util.Arrays;
import java.util.Iterator;


@Retention(RetentionPolicy.RUNTIME)
@Target(value=ElementType.TYPE)
@interface MyAnnotation
{
	String author( );
	String date( );
	int version( );
	String modifiedBy( );
	String[] reviewers();
}

//@MyAnnotation(author="Sandeep", date="18/11/2017", modifiedBy="Nikhil", version=2, reviewers = {"Yogesh","Nitin"})

@Table("EmployeeTable")
class Employee
{
	@Column("emp_name",50)
	private String name;
	
	@Id
	@Column("emp_id",5)
	private int empid;
	
	@Column("salary",10)
	private float salary;
}
public class Program 
{
	public static void main(String[] args) {
		Class<?> c = Employee.class;
		Annotation[] annotations = c.getDeclaredAnnotations();
		for (Annotation annotation : annotations)
		{
			if( annotation instanceof MyAnnotation )
			{
				MyAnnotation a = (MyAnnotation) annotation;
				System.out.println(a.author());
				System.out.println(a.date());
				System.out.println(a.modifiedBy());
				System.out.println(a.version());
				System.out.println(Arrays.toString(a.reviewers()));
			}
		}
	}
}
