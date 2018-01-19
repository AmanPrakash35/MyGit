<%@page import="java.util.Arrays"%>
<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>    
<!DOCTYPE html> 
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Insert title here</title>
	</head>
	<body>
		<form action="Second.jsp">
		<%-- <%
			List<Integer> list = Arrays.asList(10,20,30,40,50);
			session.setAttribute("List", list);
		%> --%>
		
		<%-- <%
			int[] arr = new int[]{ 10,20,30,40,50};		
			session.setAttribute("Array", arr);
		%> --%>
		
		<%-- <%
			String userName = "root";
			session.setAttribute("UserName", userName);
			
			String password = "manager";
			session.setAttribute("Password", password);
		%> --%>
		
		<c:set var="UserName" value="sandeep kulange" scope="session"/>
		<c:set var="Password" value="sunbeam pune" scope="session"/>
		<%-- <c:redirect url="Second.jsp"/> --%>
		
<%-- 		<c:url var="url" value="Second.jsp?UserName=${UserName}&&Password=${Password}"/>
		<a href="${url}">Click Here</a>		 --%>
		
		<c:url var="url" value="Second.jsp">
			<c:param name="UserName" value="sandeep kulange"/>
			<c:param name="Password" value="sunbeam pune"/>
		</c:url>
		<a href="${url}">Click Here</a>		
		<input type="submit" value="Submit"/> 
		</form>
	</body>
</html>