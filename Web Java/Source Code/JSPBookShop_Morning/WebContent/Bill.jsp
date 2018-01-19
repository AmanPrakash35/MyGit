<%@page import="java.util.Map.Entry"%>
<%@page import="java.util.Set"%>
<%@page import="pojo.Book"%>
<%@page import="java.util.Map"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html> 
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Bill Page</title>
	</head>
	<body>
		<hr/>
		<%
			Map<Book, Integer> map = (Map<Book, Integer>)request.getAttribute("map");
			Set<Entry<Book,Integer>> entries = map.entrySet();
			float totalPrice = 0;
			for(Entry<Book,Integer> entry : entries)
			{
				Book key = entry.getKey();
				int value = entry.getValue();
				totalPrice = totalPrice+key.getPrice() * value;
				%>
				<%= key %>-<%= value%><br/>
				<%
			}			
		%>
		<hr/>
		Total Price : <%= totalPrice %>
		<hr/>
	</body>
</html>