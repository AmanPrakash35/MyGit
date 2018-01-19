package pages;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class LoginServlet extends HttpServlet {
	Map<String, String> map = new HashMap<>();
	public LoginServlet() {
		map.put("Amit", "Amit");
		map.put("Prashant", "Prashant");
	}
	private static final long serialVersionUID = 1L;
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		this.handleRequest(request, response);
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		this.handleRequest(request, response);
	}
	protected void handleRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String userName = request.getParameter("txtUserName");
		String password = request.getParameter("txtPassword");
		
		response.setContentType("text/html");
		try( PrintWriter out = response.getWriter())
		{
			out.println("<html>");
			out.println("<head>");
			out.println("<title>Validation Page</title>");
			out.println("</head>");
			out.println("<body>");
			if( map.containsKey(userName))
			{
				String pswd = map.get(userName);
				if( password.equals(pswd))
					out.println("<h1>Login successful</h1>");
				else
					out.println("<h1>Invalid password</h1>");
			}
			else
				out.println("<h1>Invalid user</h1>");
			
			out.println("</body>");
			out.println("</html>");
		}
	}
}
