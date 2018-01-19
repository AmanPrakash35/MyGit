package pages;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
@WebServlet("/first")
public class FirstServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
	{
		String name = request.getParameter("txtName");		
		
		try(PrintWriter out = response.getWriter())
		{
			out.println("<html>");
			out.println("<body>");			
			out.println("<h3>Welcome : "+name+"</h3>");
			/*String url = "second?Name='"+name+"'";
			out.println("<a href='"+url+"'>Next</a>");*/
			
			
			out.println("<a href='second?Name="+name+"'>Next</a>");
			out.println("</body>");
			out.println("</html>");
		}		
	}
}
