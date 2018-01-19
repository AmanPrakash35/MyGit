package pages;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import dao.UserDao;
import pojo.User;
import utils.DBUtils;
public class RegistrationServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private UserDao dao;
	public void init(ServletConfig config) throws ServletException 
	{
		try
		{
			super.init(config);
			this.dao = new UserDao( DBUtils.getConnection());
		}
		catch (SQLException e) 
		{
			throw new ServletException(e);
		}
	}	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		this.handleRequest(request, response);
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		this.handleRequest(request, response);
	}
	protected void handleRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		User user = new User();
		user.setName(request.getParameter("txtName"));
		user.setPassword(request.getParameter("txtPassword"));
		user.setEmail(request.getParameter("txtEmail"));
		user.setMobileNumber(request.getParameter("txtMobileNumber"));
		
		response.setContentType("text/html");
		try( PrintWriter out = response.getWriter() ) 
		{			
			this.dao.registerNewUser(user);
			out.println("<h3>User registration is successful.<a href='Index.html'>click here<a> to continue</h3>");
		} catch (SQLException e) {
			throw new ServletException(e);
		}
	}
	public void destroy() 
	{
		try
		{
			this.dao.close();
		} 
		catch (IOException e) 
		{
			throw new RuntimeException(e);
		}
	}
}
