package tag;

import java.io.IOException;

import javax.servlet.jsp.JspException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.PageContext;
import javax.servlet.jsp.tagext.SimpleTagSupport;

import dao.BookDao;
import pojo.Book;

public class ShowBookTag extends SimpleTagSupport
{
	private int bookId;
	public ShowBookTag() {		
	}
	public int getBookId() {
		return bookId;
	}
	public void setBookId(int bookId) {
		this.bookId = bookId;
	}
	@Override
	public void doTag() throws JspException, IOException {
		
		Book book = null;
		try
		{
			BookDao dao = new  BookDao();		
			book = dao.getBook(bookId);
		}
		catch(Exception ex )
		{
			throw new IOException(ex);
		}		
		if( book != null )
		{
			PageContext pageContext =  (PageContext) this.getJspContext();
			JspWriter out = pageContext.getOut();
			out.println(book);
		}
	}
}
