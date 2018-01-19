package pages;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.Enumeration;
import java.util.Properties;

import javax.servlet.ServletConfig;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import dao.UserDao;
import pojo.User;
public class RegistrationServlet extends HttpServlet 
{
	private static final long serialVersionUID = 1L;
	UserDao dao = null;
	@Override
	public void init(ServletConfig config) throws ServletException 
	{	
		try
		{
			super.init(config);
			/*Properties p = new Properties();
			Enumeration<String> e = config.getInitParameterNames();
			while( e.hasMoreElements())
			{
				String name = e.nextElement();
				String value = config.getInitParameter(name);
				p.setProperty(name, value);			
			}*/
			
			Properties p = new Properties();
			ServletContext context = config.getServletContext();
			Enumeration<String> e = context.getInitParameterNames();
			while( e.hasMoreElements())
			{
				String name = e.nextElement();
				String value = context.getInitParameter(name);
				p.setProperty(name, value);			
			}
			this.dao = new UserDao( p );
		} 
		catch (Exception e)
		{
			throw new ServletException(e);
		}
	}
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
	{
		this.handleRequest(request, response);
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
	{
		this.handleRequest(request, response);
	}
	protected void handleRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
	{
		response.setContentType("text/html");
		try( PrintWriter out = response.getWriter()) 
		{
			User user = new User( request.getParameter("txtName"), request.getParameter("txtPassword"), request.getParameter("txtEmail"), request.getParameter("txtMobileNumber") );			
			dao.insertUser(user);
			dao.close();
			out.println("User registration successful");
			out.println("<a href='Index.html'>Click here to login</a>");
		} 
		catch (SQLException e)
		{
			throw new ServletException(e);
		}		
	}
	@Override
	public void destroy() 
	{
		try
		{
			dao.close();
		}
		catch (IOException e)
		{
			throw new RuntimeException(e);
		}
	}
}
