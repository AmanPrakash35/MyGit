package dependancy;

public class SoapTransport implements Transport
{
	public SoapTransport() 
	{
		System.out.println("Inside costructor	:	"+this.getClass().getName());
	}
	@Override
	public void inform(byte[] data) 
	{
		System.out.println("Informing bank using "+this.getClass().getName());
	}
}