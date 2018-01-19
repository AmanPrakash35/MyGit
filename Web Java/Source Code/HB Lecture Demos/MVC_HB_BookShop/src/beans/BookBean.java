package beans;

import java.util.List;

import dao.BookDao;
import pojo.Book;

public class BookBean
{
	private String subject;
	private BookDao dao;
	private List<Book> bookList;
	public BookBean() throws Exception{
		this.dao = new BookDao();
	}
	public String getSubject() {
		return subject;
	}
	public void setSubject(String subject) {
		this.subject = subject;
	}
	public List<Book> getBookList() {
		return bookList;
	}
	public void setBookList(List<Book> bookList) {
		this.bookList = bookList;
	}
	public void fetchBooks()throws Exception
	{
		this.bookList = this.dao.getBooks(subject);
	}
}
