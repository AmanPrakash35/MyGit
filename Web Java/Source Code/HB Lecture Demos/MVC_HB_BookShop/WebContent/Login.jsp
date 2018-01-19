<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html> 
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<form action="controller?forward=Validate" method="post">
		User Name<input type="text" name="userName"/><br/>
		Password<input type="password" name="password"/><br/>
		<input type="submit" value="Login"/>
	</form>
</body>
</html>