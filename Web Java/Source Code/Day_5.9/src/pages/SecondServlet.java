package pages;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
@WebServlet("/second")
public class SecondServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
	{
		String reqName = (String) request.getAttribute("reqName");
		
		HttpSession session = request.getSession();
		String sessionName = (String) session.getAttribute("sessionName");
		
		ServletContext application = this.getServletConfig().getServletContext();
		String applicationName = (String) application.getAttribute("applicationName");
		
		
		try(PrintWriter out = response.getWriter())
		{
			System.out.println("<html>");
			System.out.println("<body>");			
			System.out.println("Request	:	"+reqName);
			System.out.println("Session	:	"+sessionName);
			System.out.println("application	:	"+applicationName);
			System.out.println("</body>");
			System.out.println("</html>");
			response.sendRedirect("third");
		}	
	}
}
