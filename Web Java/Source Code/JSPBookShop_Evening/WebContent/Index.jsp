<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html> 
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
<jsp:useBean id="ub" class="beans.UserBean" scope="request"/>
	${requestScope.ub.message}
	<a href="Registration.jsp">New User</a><br/>
	<a href="Login.jsp">Login</a><br/>
</body>
</html>