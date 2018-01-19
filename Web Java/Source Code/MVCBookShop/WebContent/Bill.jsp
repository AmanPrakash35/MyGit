<%@page import="java.util.ArrayList"%>
<%@page import="java.util.List"%>
<%@page import="pojo.Book"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@taglib prefix="s" uri="www.sunbeaminfo.com/bookshoptag" %>    
<!DOCTYPE html> 
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<jsp:useBean id="cb" class="beans.CartBean" scope="session"/>
	<%-- <%
		
		for( int bookId : cb.getCart())
		{
			Book book = cb.getBook(bookId);
			pageContext.setAttribute("Book", book);
			%>
				${Book}
			<%
		}		
	%>	 --%>
	<c:forEach var="bookId" items="${cb.cart}">
		<s:ShowBook bookId="${bookId}"/><br/>
	</c:forEach>
</body>
</html>