<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html> 
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Registration Page</title>
	</head>
	<body>
		<form action="InsertNewUser.jsp">
			User Name<input type="text" name="txtUserName"/><br/>
			Password<input type="password" name="txtPassword"/><br/>
			Email<input type="email" name="txtEmail"/><br/>
			Contact Number<input type="tel" name="txtContactNumber"/><br/>
			<input type="submit" value="Register"/> 
		</form>
	</body>
</html>