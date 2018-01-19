package dependancy;

public class HttpTransport implements Transport
{
	public HttpTransport() 
	{
		System.out.println("Inside costructor	:	"+this.getClass().getName());
	}
	@Override
	public void inform(byte[] data) 
	{
		System.out.println("Informing bank using "+this.getClass().getName());
	}
}