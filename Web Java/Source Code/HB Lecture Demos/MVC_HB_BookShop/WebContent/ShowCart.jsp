<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html> 
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Insert title here</title>
	</head>
	<body>		
		<form action="controller?forward=Logout" method="post">
			<jsp:include page="Bill.jsp"/>
			<input type="submit" value="Logout"/>
		</form>
	</body>
</html>