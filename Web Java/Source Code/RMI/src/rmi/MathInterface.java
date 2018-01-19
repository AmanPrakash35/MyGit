package rmi;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface MathInterface  extends Remote
{
	int sum( int num1, int num2 ) throws RemoteException;
	
	int sub( int num1, int num2 ) throws RemoteException;
}
