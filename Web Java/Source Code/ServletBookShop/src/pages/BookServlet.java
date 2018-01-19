package pages;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.List;
import java.util.Set;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import dao.BookDao;
import pojo.Book;
public class BookServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private BookDao dao;
	public void init(ServletConfig config) throws ServletException 
	{
		try {
			super.init(config);
			this.dao = new BookDao();
		} catch (SQLException e) {
			throw new ServletException(e);
		}
	}	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		this.handleRequest(request, response);
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		this.handleRequest(request, response);
	}
	protected void handleRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
		try (PrintWriter out = response.getWriter())
		{
			String subject = request.getParameter("txtSubject");
			List<Book> bookList = this.dao.getBooks( subject );
			
			out.println("<html>");
			out.println("<head>");
			out.println("<title>Book Page</title>");
			out.println("</head>");
			out.println("<body>");			
			out.println("<form action='addToCart'>");
			for (Book book : bookList)
			{
				out.println("<input type='checkbox' name='chkBook' value='"+book.getBookId()+"'/>"+book.toString()+"<br/>");
			}
			out.println("<input type='submit' value='Add To Cart'>");			
			out.println("</form>");
			out.println("</body>");
			out.println("</html>");
			
		}
		catch (SQLException e) 
		{
			throw new ServletException(e);
		}
	}
	public void destroy() {
		try {
			this.dao.close();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
}
