package test;

interface Transport
{
	public void inform( byte[] data );
}
class TextTransport implements Transport
{
	@Override
	public void inform(byte[] data) 
	{
		System.out.println("Informing bank using "+this.getClass().getName());
	}
}
class HttpTransport implements Transport
{
	@Override
	public void inform(byte[] data) 
	{
		System.out.println("Informing bank using "+this.getClass().getName());
	}
}
class SoapTransport implements Transport
{
	@Override
	public void inform(byte[] data) 
	{
		System.out.println("Informing bank using "+this.getClass().getName());
	}
}
interface Atm
{
	void withdraw( float amount );
	
	void deposit( float amount );	
}
class AtmImplementation implements Atm
{
	public AtmImplementation() 
	{
		System.out.println("Inside Constructor "+this.getClass().getName());
	}
	@Override
	public void withdraw(float amount) 
	{
		StringBuilder sb = new StringBuilder("Depositing "+amount);
		Transport  transport = new HttpTransport();
		transport.inform(sb.toString().getBytes());
	}
	@Override
	public void deposit(float amount) 
	{		
		StringBuilder sb = new StringBuilder("Depositing "+amount);
		Transport  transport = new HttpTransport();
		transport.inform(sb.toString().getBytes());
	}
}
public class Program 
{
	public static void main(String[] args) 
	{
		Atm atm = new AtmImplementation();
		
		atm.deposit(5000);
	}

}
