<%@page import="beans.UserBean"%>
<%@page import="java.io.IOException"%>
<%@page import="java.sql.SQLException"%>
<%@page import="dao.UserDao"%>
<%@page import="pojo.User"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c"  uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html> 
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Insert title here</title>
	</head>
	<body>
		<jsp:useBean id="ub" class="beans.UserBean" scope="request"/>
			<jsp:setProperty name="ub" property="*" />				
				<c:redirect url="controller?forward=${ub.registerUser()}"/>
	</body>
</html>