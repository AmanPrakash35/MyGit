package pages;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import dao.BookDao;
import pojo.Book;
public class ShowCartServlet extends HttpServlet {
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
		HttpSession session =  request.getSession();
		List<Integer> cart = (List<Integer>) session.getAttribute("BookCart");		
		Map<Book, Integer> map = new HashMap<>();
		
		response.setContentType("text/html");
		try(PrintWriter out = response.getWriter()) 
		{
			for (Integer bookId : cart)
			{
				Book book = this.dao.getBook(bookId);
				if( map.containsKey(book))
				{
					int count = map.get(book);
					++ count;
					map.put(book, count);
				}
				else
					map.put(book, 1);
			}
			
			out.println("<html>");
			out.println("<head>");
			out.println("<title></title>");
			out.println("</head>");
			out.println("<body>");
			out.println("<form action='logout'>");
			Set<Entry<Book, Integer>> entries = map.entrySet();
			out.println("<hr/>");
			for (Entry<Book, Integer> entry : entries) 
			{
				Book key = entry.getKey();
				int value = entry.getValue();
				out.println(key+" "+value+"<br/>");
				
			}
			
			request.setAttribute("map", map);
			RequestDispatcher rd = request.getRequestDispatcher("bill");
			rd.include(request, response);
			
			out.println("<hr/>");			
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
