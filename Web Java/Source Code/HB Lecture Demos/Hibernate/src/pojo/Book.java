package pojo;

import java.text.SimpleDateFormat;
import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;
@Entity
@Table(name="BookTable")
public class Book
{
	private Integer bookId;
	private String title;
	private String author;
	private double price;
	private Date publishDate;
	public Book() {		
		System.out.println("Book Instance is created");
	}
	public Book(Integer bookId, String title, String author, double price, Date publishDate) {
		this.bookId = bookId;
		this.title = title;
		this.author = author;
		this.price = price;
		this.publishDate = publishDate;
	}
	@Id
	@Column(name="book_id", length=5)
	@GeneratedValue(strategy=GenerationType.IDENTITY)
	public Integer getBookId() {
		return bookId;
	}
	public void setBookId(Integer bookId) {
		this.bookId = bookId;
	}
	@Column(length=50, unique=true)
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	@Column( length=50)
	public String getAuthor() {
		return author;
	}
	public void setAuthor(String author) {
		this.author = author;
	}
	@Column(columnDefinition="double(10,2)")
	public double getPrice() {
		return price;
	}
	public void setPrice(double price) {
		this.price = price;
	}
	@Column(name="publish_date")
	@Temporal(TemporalType.DATE)
	public Date getPublishDate() {
		return publishDate;
	}
	public void setPublishDate(Date publishDate) {
		this.publishDate = publishDate;
	}
	@Override
	public String toString() {
		return String.format("%-5d%-50s%-50s%-10.2f%-15s", this.bookId, this.title, this.author, this.price,new SimpleDateFormat("dd/MMM/YYYY").format(publishDate));
	}
}
