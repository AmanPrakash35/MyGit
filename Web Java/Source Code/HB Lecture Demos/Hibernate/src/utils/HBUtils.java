package utils;
import org.hibernate.SessionFactory;
import org.hibernate.boot.MetadataSources;
import org.hibernate.boot.registry.StandardServiceRegistry;
import org.hibernate.boot.registry.StandardServiceRegistryBuilder;

public class HBUtils
{
	private static SessionFactory sessionFactory;
	static
	{
		StandardServiceRegistry serviceRegistry = new StandardServiceRegistryBuilder().configure().build();
		sessionFactory = new MetadataSources(serviceRegistry).buildMetadata().buildSessionFactory();
		System.out.println("Session Factory is crerated.");
	}
	public static SessionFactory getSessionFactory() {
		return sessionFactory;
	}
}
