package dependant;

import dependancy.Transport;

public class AtmImplementation implements Atm
{
	private Transport transport;
	public AtmImplementation( ) 
	{		
		System.out.println("Inside Constructor "+this.getClass().getName());
	}
	public AtmImplementation( Transport transport ) 
	{
		this.transport = transport;
		System.out.println("Inside Constructor "+this.getClass().getName());
	}
	public void setTransport(Transport transport)
	{
		this.transport = transport;
	}
	@Override
	public void withdraw(float amount) 
	{
		StringBuilder sb = new StringBuilder("Depositing "+amount);
		
		transport.inform(sb.toString().getBytes());
	}
	@Override
	public void deposit(float amount) 
	{		
		StringBuilder sb = new StringBuilder("Depositing "+amount);
		
		transport.inform(sb.toString().getBytes());
	}
}