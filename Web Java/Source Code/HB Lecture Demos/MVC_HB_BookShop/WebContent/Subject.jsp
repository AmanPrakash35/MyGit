<%@page import="java.util.Set"%>
<%@page import="java.io.IOException"%>
<%@page import="java.sql.SQLException"%>
<%@page import="dao.BookDao"%>
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
		<jsp:useBean id="sb" class="beans.SubjectBean" scope="page"/>
		${sb.fetchSubjects()}
		
		<form action="controller?forward=Book" method="post">
			<c:forEach var="subject" items="${sb.subjects}">
				<input type="radio" name="subject" value="${subject}" /> 
				<c:out value="${subject}"/><br/>
			</c:forEach>
			<input type="submit" value="Show Books"/>			
			<input type="submit" value="Show Cart" formaction="controller?forward=ShowCart"/>
		</form>
		
		
	</body>
</html>