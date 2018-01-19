package pages;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
@WebServlet("/second")
public class SecondServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
	{
		String name = "";
		Cookie[] cookies = request.getCookies();
		if( cookies != null )
		{
			for (Cookie cookie : cookies) 
			{
				if( cookie.getName().equals("Name"))
				{
					name = cookie.getValue();
					cookie.setMaxAge(0);
					response.addCookie(cookie);
					break;
				}
			}
		}
		
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
