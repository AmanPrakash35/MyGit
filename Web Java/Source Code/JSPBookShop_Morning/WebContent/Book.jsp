<%@page import="java.io.IOException"%>
<%@page import="pojo.Book"%>
<%@page import="java.util.List"%>
<%@page import="java.sql.SQLException"%>
<%@page import="dao.BookDao"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html> 
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Book Page</title>
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
				String subject = request.getParameter("rdSubject");
				List<Book> bookList = this.dao.getBooksBySubject(subject);
				%>
					<form action="AddToCart.jsp">
						<%  for( Book book : bookList ) { %>
							 	<input type="checkbox" name="chkBook" value="<%=book.getBookId()%>"/><%=book%><br/>
						<%	}	%>
						
						<input type="submit" value="Add To Cart"/>						
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