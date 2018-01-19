<%@page import="java.util.Set"%>
<%@page import="java.io.IOException"%>
<%@page import="java.sql.SQLException"%>
<%@page import="dao.BookDao"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html> 
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Subject Page</title>
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
				 Set<String> subjects = this.dao.getSubjects();
				%>
					<form action="Book.jsp">
						<%  for( String subject : subjects ) { %>
							 	<input type="radio" name="rdSubject" value="<%=subject%>"/><%=subject%><br/>
						<%	}	%>
						
						<input type="submit" value="Show Books"/>
						<input type="submit" value="Show Cart" formaction="ShowCart.jsp"/>
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