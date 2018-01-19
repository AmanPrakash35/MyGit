package pojo;

import java.sql.Date;

public class Book {
	private int bookId;
	private String subjectName;
	private String bookName;
	private String authorName;
	private float price;
	private Date publishDate;
	public Book() {		
	}
	public Book(int bookId, String subjectName, String bookName, String authorName, float price, Date publishDate) {
		this.bookId = bookId;
		this.subjectName = subjectName;
		this.bookName = bookName;
		this.authorName = authorName;
		this.price = price;
		this.publishDate = publishDate;
	}
	public int getBookId() {
		return bookId;
	}
	public void setBookId(int bookId) {
		this.bookId = bookId;
	}
	public String getSubjectName() {
		return subjectName;
	}
	public void setSubjectName(String subjectName) {
		this.subjectName = subjectName;
	}
	public String getBookName() {
		return bookName;
	}
	public void setBookName(String bookName) {
		this.bookName = bookName;
	}
	public String getAuthorName() {
		return authorName;
	}
	public void setAuthorName(String authorName) {
		this.authorName = authorName;
	}
	public float getPrice() {
		return price;
	}
	public void setPrice(float price) {
		this.price = price;
	}
	public Date getPublishDate() {
		return publishDate;
	}
	public void setPublishDate(Date publishDate) {
		this.publishDate = publishDate;
	}
	@Override
	public String toString() {
		return String.format("%-5d%-30s%-50s%-50s%-10.2f%-15s", this.bookId, this.subjectName, this.bookName, this.authorName, this.price, this.publishDate);
	}
}
