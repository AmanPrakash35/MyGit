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
			//out.flush();
			//response.sendRedirect("second");
			
			//RequestDispatcher rd = request.getRequestDispatcher("second");
			rd.forward(request, response);
			//rd.include(request, response);
			
			
			//ServletContext context = this.getServletConfig().getServletContext();
			//RequestDispatcher rd = context.getRequestDispatcher("/second");
			//rd.forward(request, response);
			//rd.include(request, response);
			
			out.println("</body>");
			out.println("</html>");
		}		
	}
}
