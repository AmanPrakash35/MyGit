<%@page import="java.util.HashMap"%>
<%@page import="java.util.Map"%>
<%@page import="pojo.Book"%>
<%@page import="java.util.List"%>
<%@page import="java.io.IOException"%>
<%@page import="java.sql.SQLException"%>
<%@page import="dao.BookDao"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html> 
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Show Cart</title>
	</head>
	<body>
		<%!
			BookDao dao;
			public void jspInit()
			{
				try
				{
					this.dao = new BookDao();
				}
				catch(SQLException ex)
				{
					throw new RuntimeException(ex);
				}
			}
		%>
		<%
			try
			{				
				List<Integer> cart = (List<Integer>)session.getAttribute("BookCart");
				%>
				<form action="Logout.jsp">
					<%
					Map<Book,Integer> map = new HashMap<>();
					for(int bookId : cart )
					{
						Book book = this.dao.getBook(bookId);
						if( map.containsKey(book))
						{
							int quantity = map.get(book);
							++ quantity;
							map.put(book,quantity);
						}
						else
							map.put(book,1);
					}
					request.setAttribute("map", map);
					RequestDispatcher rd = request.getRequestDispatcher("Bill.jsp");
					rd.include(request, response);
				%>
				<input type="submit" value="Logout">
				</form>
				<% 	
			}
			catch( SQLException ex )
			{
				throw new RuntimeException(ex);
			}
		%>
		<%!
			public void jspDestroy()
			{
				try
				{
					this.dao.close();
				}
				catch(IOException ex )
				{
					throw new RuntimeException(ex);
				}
			}
		%>
	</body>
</html>