package test;

import java.lang.reflect.Field;

class Complex
{
	private int real;
	private int imag;
	public void print()
	{
		System.out.println("Real	:	"+this.real);
		System.out.println("Imag	:	"+this.imag);
	}
}
public class Program {
	public static void main(String[] args) {
		try {
			Complex c1 = new Complex();
			
			Class<?> c = c1.getClass();
			Field field = null;
			
			field = c.getDeclaredField("real");
			field.setAccessible(true);
			field.set(c1, 10);
			
			field = c.getDeclaredField("imag");
			field.setAccessible(true);
			field.set(c1, 20);
			
			c1.print();
		}catch (Exception e) {			
			e.printStackTrace();
		}
	}
}
