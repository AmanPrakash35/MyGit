package controller;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
public class BookShopController extends HttpServlet {
	private static final long serialVersionUID = 1L;
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		this.handleRequest(request, response);
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		this.handleRequest(request, response);
	}
	protected void handleRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String name =  request.getParameter("forward");
		RequestDispatcher rd = null;
		if( name.equals("Index"))			
			rd = request.getRequestDispatcher("Index.jsp");
		else if( name.equals("Registration"))			
			rd = request.getRequestDispatcher("Registration.jsp");
		else if( name.equals("AddUser"))
			rd = request.getRequestDispatcher("AddUser.jsp");
		else if( name.equals("Login"))
			rd = request.getRequestDispatcher("Login.jsp");
		else if( name.equals("Validate"))
			rd = request.getRequestDispatcher("Validate.jsp");
		else if( name.equals("Subject"))
			rd = request.getRequestDispatcher("Subject.jsp");
		else if( name.equals("Book"))
			rd = request.getRequestDispatcher("Book.jsp");
		else if( name.equals("AddToCart"))
			rd = request.getRequestDispatcher("AddToCart.jsp");
		else if( name.equals("ShowCart"))
			rd = request.getRequestDispatcher("ShowCart.jsp");
		else if( name.equals("Logout"))
			rd = request.getRequestDispatcher("Logout.jsp");
		rd.forward(request, response);
	}
}
