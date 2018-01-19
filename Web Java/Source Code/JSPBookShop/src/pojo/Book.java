package pojo;
import java.sql.Date;

public class Book
{
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
