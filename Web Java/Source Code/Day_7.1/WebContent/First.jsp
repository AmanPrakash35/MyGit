<%@page import="java.util.Enumeration"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html> 
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%-- <%
		String value = config.getInitParameter("Author");
		out.println(value);
	%> --%>
	
	<%-- <%= config.getInitParameter("Author") %> --%>
	
	<%-- <%
		String version =  application.getInitParameter("Version");
		out.println( version);
	%> --%>
	
	<%-- <%= application.getInitParameter("Version") %> --%>
	
	<%-- <%
		Enumeration<String> e = request.getHeaderNames();
		while( e.hasMoreElements())
		{
			String key = e.nextElement();
			
			String value = request.getHeader(key);
			out.println("<h1>"+key+":"+value+"</h1>");
		}
	%> --%>
	
	<%
		Enumeration<String> e = request.getHeaderNames();
		while( e.hasMoreElements())
		{
			String key = e.nextElement();
			
			String value = request.getHeader(key);
			out.println("<h1>"+key+":"+value+"</h1>");
		}
	%>
</body>
</html>