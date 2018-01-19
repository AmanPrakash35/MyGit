package beans;

import java.util.ArrayList;
import java.util.List;

import dao.BookDao;
import pojo.Book;

public class CartBean {
	private String[] bookIds;
	private List<Integer> cart;
	private BookDao dao;
	public CartBean() throws Exception{	
		this.dao = new BookDao();
		this.cart = new ArrayList<Integer>();
	}
	public String[] getBookIds() {
		return bookIds;
	}
	public void setBookIds(String[] bookIds) {
		this.bookIds = bookIds;
	}
	public List<Integer> getCart() {
		return cart;
	}
	public void setCart(List<Integer> cart) {
		this.cart = cart;
	}
	public String addToCart()
	{
		for (String bookId : bookIds) {
			this.cart.add(Integer.parseInt(bookId));
		}
		return "Subject";
	}
	public Book getBook( int bookId )throws Exception
	{
		return this.dao.getBook(bookId);
	}	
}
