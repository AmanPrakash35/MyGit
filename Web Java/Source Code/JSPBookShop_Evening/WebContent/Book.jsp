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
		<jsp:useBean id="bb" class="beans.BookBean" scope="page"/>
			<jsp:setProperty name="bb" property="subject" />
				${bb.fetchBooks()}
			<form action="AddToCart.jsp">	
				<%
					for(Book book : bb.getBookList())
					{
						pageContext.setAttribute("Book", book );
						%>
							<input type="checkbox" name="book" value="${Book.bookId}">${Book}<br/>		
						<%
					}
				%>	
				<input type="submit" value="Add To Cart"/>
			</form> 
	</body>
</html>