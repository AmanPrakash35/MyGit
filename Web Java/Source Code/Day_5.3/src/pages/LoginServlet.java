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
public class LoginServlet extends HttpServlet 
{
	private static final long serialVersionUID = 1L;
	UserDao dao;
	@Override
	public void init(ServletConfig config) throws ServletException 
	{	
		try
		{
			super.init(config);
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
		} catch (Exception e) {
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
		try {
			User user =  this.dao.getUserDetails(request.getParameter("txtName"), request.getParameter("txtPassword"));
			if( user != null )
				response.sendRedirect("details");
			else
			{
				try( PrintWriter out = response.getWriter())
				{
					out.println("<h3>Login failed</h3><br/>");
					out.println("<a href='Index.html'>Retry</a>");
				}
			}
		} catch (SQLException e) 
		{
			throw new ServletException(e);
		}
	}
	@Override
	public void destroy() 
	{
		try {
			this.dao.close();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
}
