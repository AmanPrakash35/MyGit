<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@taglib prefix="form" uri="http://www.springframework.org/tags/form" %>
<!DOCTYPE html> 
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Insert title here</title>
	</head>
	<body>
		<form:form modelAttribute="customer" method="post">
			<table>
				<tr>
					<td>Name</td>
					<td><form:input path="name"/> </td>
				</tr>
				<tr>
					<td>Email</td>
					<td><form:input path="email"/></td>
				</tr>
				<tr>
					<td>Password</td>
					<td> <form:password path="password"/> </td>
				</tr>
				<tr>
					<td>Role</td>
					<td><form:input path="role"/></td>
				</tr>
				<tr>
					<td>Registration Date</td>
					<td><form:input path="regDate"/></td>
				</tr>
				<tr>
					<td></td>
					<td> <input type="submit" value="Register"/>  </td>
				</tr>
			</table>
		</form:form>
	</body>
</html>