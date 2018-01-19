package test;

import java.lang.reflect.Method;
import java.lang.reflect.Parameter;
import java.util.Scanner;

class Convert 
{
	public static Object changeType( String value, Parameter parameter )
	{
		switch( parameter.getType().getName())
		{
		case "int":
			return Integer.parseInt(value);
		case "float":
			return Float.parseFloat(value);
		}
		return null;
	}
}
public class Program 
{	
	public static void main(String[] args) 
	{
		try( Scanner sc = new Scanner(System.in))
		{
			System.out.print("F.Q. Class Name	:	");	//math.Calculator
			String className = sc.nextLine();			
			Class<?> c = Class.forName(className);
			
			System.out.print("Method name	:	");
			String methodName = sc.nextLine();
			
			boolean exist = false;
			Method[] methods = c.getMethods();
			for (Method method : methods)
			{
				if( method.getName().equalsIgnoreCase(methodName))
				{
					exist = true;
					
					Object obj = c.newInstance();
					
					Parameter[] parameters = method.getParameters();
					Object[] arguments = new Object[ parameters.length ];
					for( int index = 0; index < parameters.length; ++ index )
					{
						System.out.println("Enter value for argument of "+parameters[ index ].getType().getName()+"	type	:	");
						String value = sc.nextLine();
						arguments[ index ] = Convert.changeType( value, parameters[ index ] );
					}					
					Object result = method.invoke(obj, arguments);
					System.out.println("Result	:	"+result);
				}
			}
			if( !exist )
				System.out.println("method does not exist");
		} 
		catch (Exception e) 
		{			
			System.out.println("Invalid class name");
		}
	}		
}
