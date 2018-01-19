<%@page import="java.io.IOException"%>
<%@page import="java.sql.SQLException"%>
<%@page import="dao.UserDao"%>
<%@page import="pojo.User"%>
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
			User user = new User();
			user.setName(request.getParameter("txtName"));
			user.setPassword(request.getParameter("txtPassword"));
			user.setEmail(request.getParameter("txtEmail"));
			user.setMobileNumber(request.getParameter("txtMobileNumber"));
			this.dao.registerNewUser(user);
		%>
			Registration is successful. <a href="Index.html">Click here</a> to continue.
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
				catch( IOException ex)
				{
					throw new RuntimeException(ex);
				}
			}
		%>
	</body>
</html>