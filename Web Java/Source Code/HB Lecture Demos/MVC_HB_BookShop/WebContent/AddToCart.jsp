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
	<jsp:setProperty name="cb" property="bookIds" param="book"/>
		<jsp:forward page="controller?forward=${cb.addToCart()}"/>	
</body>
</html>