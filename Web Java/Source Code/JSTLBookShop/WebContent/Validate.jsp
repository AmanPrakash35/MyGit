<%@page import="beans.UserBean"%>
<%@page import="java.util.ArrayList"%>
<%@page import="java.util.List"%>
<%@page import="java.io.IOException"%>
<%@page import="pojo.User"%>
<%@page import="java.sql.SQLException"%>
<%@page import="dao.UserDao"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html> 
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Insert title here</title>
	</head>
	<body>
		<jsp:useBean id="ub" class="beans.UserBean" scope="page"/>
			<jsp:setProperty name="ub" property="*" />
				<jsp:forward page="${ub.validateUser()}.jsp"/>
	</body>
</html>