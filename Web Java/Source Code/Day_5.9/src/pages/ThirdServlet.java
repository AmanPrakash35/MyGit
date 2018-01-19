package pages;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
@WebServlet("/third")
public class ThirdServlet extends HttpServlet {
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
			out.println("<html>");
			out.println("<body>");			
			out.println("Request	:	"+reqName);
			out.println("Session	:	"+sessionName);
			out.println("application	:	"+applicationName);
			out.println("</body>");
			out.println("</html>");
		}	
	}
}
