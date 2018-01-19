<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" isErrorPage="true"%>
<!DOCTYPE html> 
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<h3>Error Page</h3>
	<%		
		out.println(exception+"<br/><br/>");
		ErrorData errorData = pageContext.getErrorData();
		out.println(errorData.getRequestURI()+"<br/>");
		out.println(errorData.getServletName()+"<br/>");
		out.println(errorData.getStatusCode()+"<br/>");
		out.println(errorData.getThrowable()+"<br/>");
	%>
</body>
</html>