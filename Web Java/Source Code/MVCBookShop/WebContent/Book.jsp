<%@page import="pojo.Book"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
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
			<form action="controller?forward=AddToCart" method="post">				
				<c:forEach var="book" items="${bb.bookList}">
					<input type="checkbox" name="book" value="${book.bookId}"/>
					<c:out value="${book}"/><br/>
				</c:forEach>
				<input type="submit" value="Add To Cart"/>
			</form> 
	</body>
</html>