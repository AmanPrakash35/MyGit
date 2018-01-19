package pages;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.Set;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import dao.BookDao;
public class SubjectServlet extends HttpServlet {
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
			Set<String> subjects = this.dao.getSubjects();
			out.println("<html>");
			out.println("<head>");
			out.println("<title>Subject Page</title>");
			out.println("</head>");
			out.println("<body>");			
			out.println("<form action='book'>");
			for (String subject : subjects) 
			{
				out.println("<input type='radio' name='txtSubject' value='"+subject+"'/>"+subject+"<br/>");
			}
			out.println("<input type='submit' value='Show Books'>");
			out.println("<a href='showCart'>Show Cart</a>");
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
