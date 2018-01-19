package pages;

import java.io.IOException;
import java.io.PrintWriter;

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
		HttpSession session = request.getSession( );
		String name = (String) session.getAttribute("UserName");
		
		try(PrintWriter out = response.getWriter())
		{
			out.println("<html>");
			out.println("<body>");			
			out.println("<h3>Hello : "+name+"</h3>");			
			out.println("</body>");
			out.println("</html>");
		}	
	}
}