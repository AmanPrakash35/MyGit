	package test;

class A
{
	void print()
	{
		B b = new B();
		b.print();
	}
}
class B
{
	public void print()
	{
		System.out.println("Hello");
	}
}
public class Program {

	public static void main(String[] args) {
		A a = new A();
		a.print();
	}

}
