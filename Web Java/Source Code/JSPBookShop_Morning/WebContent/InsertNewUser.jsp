<%@page import="java.sql.Date"%>
<%@page import="java.time.LocalDate"%>
<%@page import="pojo.User"%>
<%@page import="java.io.IOException"%>
<%@page import="java.sql.SQLException"%>
<%@page import="dao.UserDao"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html> 
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Insert New User</title>
	</head>
	<body>
		<%!
			UserDao dao;			
			public void jspInit()
			{ 
				try
				{
					this.dao = new UserDao();
				}
				catch(SQLException ex )
				{
					throw new RuntimeException(ex);
				}
				
			}
		%>
		<%
			User user = new User( );
			user.setUserName(request.getParameter("txtUserName"));
			user.setPassword(request.getParameter("txtPassword"));
			user.setEmail(request.getParameter("txtEmail"));
			user.setContactNumber(request.getParameter("txtContactNumber"));
			user.setAccountCreationDate(Date.valueOf(LocalDate.now()));
			this.dao.insertUser(user);
		%>
		User registration is successful. <a href="Index.html">Click here</a> to continue...
		<%!
			public void jspDestroy()
			{
				try
				{
					this.dao.close();
				}
				catch(IOException ex )
				{
					throw new RuntimeException( ex );
				}
			}
		%>
	</body>
</html>