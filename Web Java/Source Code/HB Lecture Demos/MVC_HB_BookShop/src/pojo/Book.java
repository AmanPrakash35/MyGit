package pojo;
import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;

@Entity
@Table( name="BookTable")
public class Book
{
	private Integer bookId;
	private String subjectName;
	private String bookName;
	private String authorName;
	private float price;
	private Date publishDate;
	public Book() {	
	}
	public Book(Integer bookId, String subjectName, String bookName, String authorName, float price, Date publishDate) {		
		this.bookId = bookId;
		this.subjectName = subjectName;
		this.bookName = bookName;
		this.authorName = authorName;
		this.price = price;
		this.publishDate = publishDate;
	}
	@Id	
	@Column(name="book_id")
	public Integer getBookId() {
		return bookId;
	}
	public void setBookId(Integer bookId) {
		this.bookId = bookId;
	}
	@Column(name="subject_name", length=50)
	public String getSubjectName() {
		return subjectName;
	}
	public void setSubjectName(String subjectName) {
		this.subjectName = subjectName;
	}
	@Column(name="book_name", length=50, unique=true)
	public String getBookName() {
		return bookName;
	}
	public void setBookName(String bookName) {
		this.bookName = bookName;
	}
	@Column(name="author_name", length=50)
	public String getAuthorName() {
		return authorName;
	}
	public void setAuthorName(String authorName) {
		this.authorName = authorName;
	}
	@Column(columnDefinition="float(10,2)")
	public float getPrice() {
		return price;
	}
	public void setPrice(float price) {
		this.price = price;
	}
	@Temporal(TemporalType.DATE)
	@Column(name="publish_date")
	public Date getPublishDate() {
		return publishDate;
	}
	public void setPublishDate(Date publishDate) {
		this.publishDate = publishDate;
	}

	
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + bookId;
		return result;
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Book other = (Book) obj;
		if (bookId != other.bookId)
			return false;
		return true;
	}
	@Override
	public String toString() {
		return String.format("%-30s%-30s%-10.2f", this.bookName, this.authorName, this.price);
	}
}
