<%@page import="java.util.ArrayList"%>
<%@page import="java.util.List"%>
<%@page import="pojo.Book"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html> 
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<jsp:useBean id="cb" class="beans.CartBean" scope="session"/>
	<%
		
		for( int bookId : cb.getCart())
		{
			Book book = cb.getBook(bookId);
			pageContext.setAttribute("Book", book);
			%>
				${Book}
			<%
		}		
	%>
</body>
</html>