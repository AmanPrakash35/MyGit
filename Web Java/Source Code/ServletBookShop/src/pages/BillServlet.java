package pages;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Map;
import java.util.Set;
import java.util.Map.Entry;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import pojo.Book;
public class BillServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
		
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		this.handleRequest(request, response);
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		this.handleRequest(request, response);
	}
	protected void handleRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		Map<Book,Integer> map = (Map<Book, Integer>) request.getAttribute("map");
		Set<Entry<Book, Integer>> entries = map.entrySet();
		float totalPrice = 0;
		for (Entry<Book, Integer> entry : entries) 
		{
			Book key = entry.getKey();
			int quantity = entry.getValue();
			
			totalPrice = totalPrice + key.getPrice() * quantity;
		}
		try( PrintWriter out = response.getWriter())
		{
			out.println("Total Price : "+totalPrice);
			out.println("<input type='submit' value='Logout'/>");
		}
	}	
}
