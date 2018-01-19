<%@page import="pojo.UserDetails"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html> 
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Third Page</title>
	</head>
<body>
	<%-- <%
		UserDetails userDetails1 = ( UserDetails )pageContext.getAttribute("UserDetails");
		if( userDetails1 != null)
			out.println("<h1>Page : "+userDetails1.getEmail()+"</h1><br/>");
	
		UserDetails userDetails2 = ( UserDetails )request.getAttribute("UserDetails");
			if(userDetails2 != null)
		out.println("<h1>Request : "+userDetails2.getEmail()+"</h1><br/>");
	
		UserDetails userDetails3 = ( UserDetails )session.getAttribute("UserDetails");
		if(userDetails3 != null)
			out.println("<h1>Session : "+userDetails3.getEmail()+"</h1><br/>");
		
	
		UserDetails userDetails4 = ( UserDetails )application.getAttribute("UserDetails");
		if(userDetails4 != null)
			out.println("<h1>Application : "+userDetails4.getEmail()+"</h1><br/>");
	%> --%>
	
	<%-- <%
		UserDetails userDetails1 = ( UserDetails )pageContext.getAttribute("UserDetails", PageContext.PAGE_SCOPE);
		if( userDetails1 != null)
			out.println("<h1>Page : "+userDetails1.getEmail()+"</h1><br/>");
	
		UserDetails userDetails2 = ( UserDetails )pageContext.getAttribute("UserDetails", PageContext.REQUEST_SCOPE);
			if(userDetails2 != null)
		out.println("<h1>Request : "+userDetails2.getEmail()+"</h1><br/>");
	
		UserDetails userDetails3 = ( UserDetails )pageContext.getAttribute("UserDetails",PageContext.SESSION_SCOPE);
		if(userDetails3 != null)
			out.println("<h1>Session : "+userDetails3.getEmail()+"</h1><br/>");
		
	
		UserDetails userDetails4 = ( UserDetails )pageContext.getAttribute("UserDetails",PageContext.APPLICATION_SCOPE);
		if(userDetails4 != null)
			out.println("<h1>Application : "+userDetails4.getEmail()+"</h1><br/>");
	%> --%>
	
	<%-- <h1>Page : <%=(( UserDetails)pageContext.getAttribute("UserDetails")).getEmail()%></h1><br/>
	<h1>Request : <%=(( UserDetails)request.getAttribute("UserDetails")).getEmail()%></h1><br/>
	<h1>Session : <%=(( UserDetails)session.getAttribute("UserDetails")).getEmail()%></h1><br/>
	<h1>Application : <%=(( UserDetails)application.getAttribute("UserDetails")).getEmail()%></h1><br/> --%>


	
	<%-- <h1>Application : ${applicationScope.Name}</h1><br/>
	<h1>Application : ${applicationScope.Email}</h1><br/>
	<h1>Application : ${applicationScope.MobileNumber}</h1><br/> --%>

<%-- <h1>Session : ${sessionScope.Name}</h1><br/>
<h1>Session : ${sessionScope.Email}</h1><br/>
<h1>Session : ${sessionScope.MobileNumber}</h1><br/> --%>
		
		<%-- <h1>Request : ${requestScope.Name}</h1><br/>
		<h1>Request : ${requestScope.Email}</h1><br/>
		<h1>Request : ${requestScope.MobileNumber}</h1><br/> --%>
		
		<%-- <h1>Request : <%= pageContext.getAttribute("Name")%></h1><br/>
		
		<h1>Page : ${pageScope.Name}</h1><br/> --%>

	<%-- <h1>Name : ${applicationScope.UserDetails.name}</h1><br/>
	<h1>Email : ${applicationScope.UserDetails.email}</h1><br/>
	<h1>MobileNumber : ${applicationScope.UserDetails.mobileNumber}</h1><br/>
	 --%>
	 	
</body>
</html>