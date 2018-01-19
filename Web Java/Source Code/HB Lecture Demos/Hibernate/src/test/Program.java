package test;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;

import dao.BookDao;
import pojo.Book;
import utils.HBUtils;

public class Program 
{
	/*public static void main(String[] args) 
	{
		SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-YYYY");
		try( Scanner sc = new Scanner(System.in))
		{
			Book book = new Book();
			System.out.println("Enter book details:");
			System.out.print("Title	:	");
			book.setTitle(sc.nextLine());
			System.out.print("Author	:	");
			book.setAuthor(sc.nextLine());
			System.out.print("Price	:	");
			book.setPrice(sc.nextFloat());
			System.out.print("Publish Date	:	");
			sc.nextLine();
			book.setPublishDate(sdf.parse(sc.nextLine()));
			
			BookDao dao = new  BookDao();
			Integer  bookId = dao.addBook2(book);
			System.out.println("Book is added with book id : "+bookId);
			HBUtils.getSessionFactory().close();
		}
		catch(Exception ex)
		{
			ex.printStackTrace();
		}
	}*/
	/*public static void main(String[] args) 
	{		
		try( Scanner sc = new Scanner(System.in))
		{			
			BookDao dao = new  BookDao();
			System.out.print("Enter book id	:	");
			int bookId = sc.nextInt();
			
			Book book = dao.getBookDetails( bookId );
			System.out.println(book.toString());
			
			HBUtils.getSessionFactory().close();
		}
		catch(Exception ex)
		{
			ex.printStackTrace();
		}
	}*/
	/*public static void main(String[] args) 
	{		
		BookDao dao = new  BookDao();
		List<Book> bookList = dao.getAllBooks();
		bookList.forEach(System.out::println);
		HBUtils.getSessionFactory().close();		
	}*/
	
	/*public static void main(String[] args) 
	{		
		SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-YYYY");
		try( Scanner sc = new Scanner(System.in))
		{			
			BookDao dao = new  BookDao();
			
			System.out.print("Enter author name	:	");
			String authorName = sc.nextLine();
			
			System.out.print("Enter publish date	:	");
			Date publishDate = sdf.parse(sc.nextLine());
			
			List<Book> bookList = dao.getBooksByCriteria( authorName, publishDate);
			bookList.forEach(System.out::println);
			
			HBUtils.getSessionFactory().close();
		}
		catch(Exception ex)
		{
			ex.printStackTrace();
		}
	}*/
	/*public static void main(String[] args) 
	{		
		SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-YYYY");
		try( Scanner sc = new Scanner(System.in))
		{			
			BookDao dao = new  BookDao();
						
			System.out.print("Enter publish date	:	");
			Date publishDate = sdf.parse(sc.nextLine());
			
			System.out.print("Enter amount	:	");
			double amount = sc.nextDouble();
			
			int updateCount = dao.applyDiscount(publishDate, amount);
			System.out.println(updateCount+" books updated");
			
			HBUtils.getSessionFactory().close();
		}
		catch(Exception ex)
		{
			ex.printStackTrace();
		}
	}*/
	/*public static void main(String[] args) 
	{		
		SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-YYYY");
		try( Scanner sc = new Scanner(System.in))
		{			
			BookDao dao = new  BookDao();
						
			System.out.print("Enter publish date	:	");
			Date publishDate = sdf.parse(sc.nextLine());
			
			List<Book> bookList = dao.deleteBooks(publishDate);
			bookList.forEach(System.out::println);
			
			HBUtils.getSessionFactory().close();
		}
		catch(Exception ex)
		{
			ex.printStackTrace();
		}
	}*/
	public static void main(String[] args) 
	{		
		SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-YYYY");
		try( Scanner sc = new Scanner(System.in))
		{			
			BookDao dao = new  BookDao();
			
			dao.saveBook_1();	
			
			//dao.saveBook_2();
			
			//dao.saveBook_3();
			
			//dao.persistBook_1();
			
			//dao.persistBook_2();
			
			//dao.persistBook_3();
			
			dao.save_or_updateBook();
			
			HBUtils.getSessionFactory().close();
		}
		catch(Exception ex)
		{
			ex.printStackTrace();
		}
	}
}
