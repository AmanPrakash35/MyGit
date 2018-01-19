package client;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

import rmi.MathInterface;

public class Client 
{
	public static final int PORT = 5123;
	public static void main(String[] args) {
		try
		{		
			Registry registry = LocateRegistry.getRegistry( PORT );
		 	MathInterface mathObject  = (MathInterface) registry.lookup("MathObject");
		 	System.out.println("Sum	:	"+mathObject.sum(100, 20));
		 	System.out.println("Sub	:	"+mathObject.sub(100, 20));
		}
		catch(Exception ex)
		{
			ex.printStackTrace();
		}
	}
}
