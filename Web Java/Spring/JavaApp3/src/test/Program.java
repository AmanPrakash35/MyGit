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
	private Transport transport;
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
public class Program 
{
	/*public static void main(String[] args) 
	{
		AtmImplementation atm = new AtmImplementation();
		
		//Transport transport = new HttpTransport();
		
		//Transport transport = new SoapTransport();
		
		Transport transport = new TextTransport();
				
		atm.setTransport(transport);
		
		atm.deposit(5000);
	}*/
	
	public static void main(String[] args) 
	{
		Transport transport = null;
		
		//transport = new TextTransport();
		
		//transport = new HttpTransport();
		
		transport = new SoapTransport();
		
		AtmImplementation atm = new AtmImplementation( transport );
		
		atm.deposit(5000);
	}

}
