package pages;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Enumeration;
import java.util.HashMap;
import java.util.Map;
import java.util.Properties;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class LoginServlet extends HttpServlet {
	
	public LoginServlet() {
	
	}
	private static final long serialVersionUID = 1L;
	/*@Override
	public void init() throws ServletException {
		ServletConfig config = this.getServletConfig();
		Properties p = new Properties();
		Enumeration<String> e = config.getInitParameterNames();
		while( e.hasMoreElements())
		{
			String name = e.nextElement();
			String value = config.getInitParameter(name);
			p.setProperty(name, value);			
		}
		System.out.println(p.toString());
	}*/
	@Override
	public void init(ServletConfig config) throws ServletException {		
		super.init(config);		
		Properties p = new Properties();
		Enumeration<String> e = config.getInitParameterNames();
		while( e.hasMoreElements())
		{
			String name = e.nextElement();
			String value = config.getInitParameter(name);
			p.setProperty(name, value);			
		}
		System.out.println(p.toString());
	}
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		this.handleRequest(request, response);
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		this.handleRequest(request, response);
	}
	protected void handleRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		System.out.println(this.getServletConfig());
		
		/*String userName = request.getParameter("txtUserName");
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
		}*/		
	}	
}
