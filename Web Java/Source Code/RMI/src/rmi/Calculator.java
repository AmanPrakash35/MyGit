package rmi;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class Calculator extends UnicastRemoteObject implements MathInterface 
{	
	public Calculator() throws RemoteException {		
	}
	@Override
	public int sum(int num1, int num2) {
		return num1 + num2;
	}
	@Override
	public int sub(int num1, int num2) {
		return num1 - num2;
	}
}
