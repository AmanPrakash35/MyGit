<%@page import="java.util.ArrayList"%>
<%@page import="java.util.List"%>
<%@page import="java.io.IOException"%>
<%@page import="pojo.User"%>
<%@page import="java.sql.SQLException"%>
<%@page import="dao.UserDao"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html> 
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Insert title here</title>
	</head>
	<body>
		<%!
			UserDao dao;
			public void jspInit( )
			{
				try
				{
					this.dao = new  UserDao();
				}
				catch(SQLException ex )
				{
					throw new RuntimeException(ex);
				}
			}
		%>
		<%
		try
		{			
			String userName = request.getParameter("txtName");
			String password = request.getParameter("txtPassword");
			User user = this.dao.authenticateUser(userName, password);
			if( user != null )
			{
				
				List<Integer> cart = new ArrayList<>();
				session.setAttribute("BookCart", cart);
				
				String url = response.encodeRedirectURL("Subject.jsp");
				response.sendRedirect(url);
			}
			else
			{
			%>
				Invalid user name or password.<a href="Index.html">Retry</a>
			<%	
			}
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
				catch( IOException ex)
				{
					throw new RuntimeException(ex);
				}
			}
		%>	
	</body>
</html>
