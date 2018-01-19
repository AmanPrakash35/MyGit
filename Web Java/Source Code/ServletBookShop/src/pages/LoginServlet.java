package pages;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import dao.UserDao;
import pojo.User;
import utils.DBUtils;
public class LoginServlet extends HttpServlet {
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
		String name = request.getParameter("txtName");
		String password  = request.getParameter("txtPassword");
				
		response.setContentType("text/html");
		try( PrintWriter out = response.getWriter() ) 
		{			
			User user = this.dao.authenticateUser(name, password);
			if( user != null )
			{
				List<Integer> cart = new  ArrayList<Integer>();
				HttpSession session = request.getSession();
				session.setAttribute("BookCart", cart);
				
				response.sendRedirect("subject");
			}
			else
				out.println("<h3>Invalid username or password.<a href='Index.html'>Try again</a><h3>");
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
