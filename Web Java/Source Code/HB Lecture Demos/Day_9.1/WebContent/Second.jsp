<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>    
<!DOCTYPE html> 
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%-- <%
		List<Integer> list =  ( List<Integer>)session.getAttribute("List");
		for( int element : list )
		{
			out.println("<h2>"+element+"</h2><br/>");
		}
	%> --%>
	
<%-- 	<c:forEach var="element" items="${List}">		
		<c:out value="${element}"/><br/>
	</c:forEach> --%>
	
	<%-- <c:forEach var="element" items="${Array}">		
		<c:out value="${element}"/><br/>
	</c:forEach> --%>
	
	<%-- <c:forEach var="element" begin="0"  end="4" items="${Array}">		
		<c:out value="${element}"/><br/>
	</c:forEach> --%>
	
	<%-- User Name:<c:out value="${UserName}"/><br/>
	Password:<c:out value="${Password}"/><br/> --%>
	
	<%-- <c:if test="${UserName eq 'root'}"> --%>
	<%-- <c:if test="${UserName=='root'}">
		<c:out value="Login is successful"/>
	</c:if>	 --%>
	
<%-- 	<c:choose>
		<c:when test="${UserName eq 'root'}">
			<c:out value="Login is successful"/>
		</c:when>
		<c:otherwise>
			<c:out value="Login is unsuccessful"/>
		</c:otherwise>
	</c:choose>	 --%>
	
	<%-- <%
		String userName = request.getParameter("UserName");
		String password = request.getParameter("Password");
		out.println(userName+"<br/>");
		out.println(password+"<br/>");
	%> --%>
	
	<c:out value="${UserName}"/><br/>
	<c:out value="${Password}"/><br/>
</body>
</html>