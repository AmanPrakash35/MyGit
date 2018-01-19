package org.sunbeam.dac.test;

import java.lang.annotation.ElementType;
import java.lang.annotation.Repeatable;
import java.lang.annotation.Target;

@Repeatable( Authors.class)
@interface Author
{
	String name();
	int version();
}

@interface Authors
{
	Author[] value();
}

@Author(name="ABC",version = 1)
@Author(name="ABC",version = 1)
class Employee
{
	
}
public class Program 
{
	public static void main(String[] args) {

	}
}
