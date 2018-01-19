package server;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

import rmi.Calculator;
import rmi.MathInterface;

public class Server 
{
	public static final int PORT = 5123;
	public static void main(String[] args)
	{
		try
		{
			Remote remoteObject = new Calculator();
			Registry registry = LocateRegistry.getRegistry( PORT);
			registry.rebind("MathObject", remoteObject);
			System.out.println("Server is started....");
		} 
		catch (Exception e)
		{			
			e.printStackTrace();
		}		
	}
}
