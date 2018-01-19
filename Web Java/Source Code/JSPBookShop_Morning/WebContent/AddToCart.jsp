<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html> 
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Add to cart</title>
	</head>
	<body>
		<%
			List<Integer> cart = ( List<Integer> )session.getAttribute("BookCart");
			String[] values = request.getParameterValues("chkBook");
			for( String value : values )
			{
				cart.add( Integer.parseInt(value));
			}
			response.sendRedirect("Subject.jsp");
		%>
	</body>
</html>