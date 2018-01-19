package dto;

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
	}	
	public Book(String title, String author, double price, Date publishDate) {
		this.title = title;
		this.author = author;
		this.price = price;
		this.publishDate = publishDate;
	}
	@Id
	@GeneratedValue(strategy= GenerationType.AUTO)
	@Column(name="book_id")
	public Integer getBookId() {
		return bookId;
	}
	public void setBookId(Integer bookId) {
		this.bookId = bookId;
	}
	@Column( length=30)
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	@Column( length=30)
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
		return "Book [bookId=" + bookId + ", title=" + title + ", author=" + author + ", price=" + price
				+ ", publishDate=" + publishDate + "]";
	}
	
}
