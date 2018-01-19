package test;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.Scanner;

public class Program 
{
	public static void printClassInfo(Class<?> c )
	{
		String packageName  = c.getPackage().getName();
		System.out.println("Package Name	:	"+packageName);
		String className = c.getSimpleName();
		System.out.println("Class Name	:	"+className);				
	}
	public static void printFieldInfo( Class<?> c )
	{
		Field[] fields = c.getFields();
		for (Field field : fields) {
			System.out.println(field.toString());
		}
	}
	public static void printConstructorInfo( Class<?> c)
	{
		Constructor<?>[] constructors = c.getConstructors();
		for (Constructor<?> constructor : constructors) {
			System.out.println(constructor.toString());
		}
	}
	public static void printMethodInfo( Class<?> c )
	{
		Method[] methods = c.getMethods();
		for (Method method : methods) {
			System.out.println(method.toString());
		}
	}
	public static void main(String[] args) 
	{
		try( Scanner sc = new Scanner(System.in))
		{
			System.out.print("F.Q. Class Name	:	");
			String className = sc.nextLine();
			
			Class<?> c = Class.forName(className);
			
			//Program.printClassInfo(c);
			
			//Program.printFieldInfo(c);
			
			//Program.printConstructorInfo();
			
			Program.printMethodInfo(c);
		} 
		catch (Exception e) 
		{			
			e.printStackTrace();
		}
	}		
}
