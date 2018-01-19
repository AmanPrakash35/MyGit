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
		<title>Insert title here</title>
	</head>
	<body>
		<jsp:useBean id="sb" class="beans.SubjectBean" scope="page"/>
		${sb.fetchSubjects()}
		
		<form action="Book.jsp">
			<%			
				for( String subject : sb.getSubjects() )
				{
					pageContext.setAttribute("subject", subject);
					%>
						<input type="radio" name="subject" value="${subject}" /> ${subject}<br/>
					<% 		
				}
			%>
			<input type="submit" value="Show Books"/>			
			<input type="submit" value="Show Cart" formaction="ShowCart.jsp"/>
		</form>
		
		
	</body>
</html>