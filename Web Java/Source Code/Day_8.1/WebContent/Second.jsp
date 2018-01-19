<%@page import="pojo.UserDetails"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html> 
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Second Page</title>
	</head>
	<body>
		<%	
		/* String name = request.getParameter("name");
		session.setAttribute("Name", name); */
		
		
			/* String name = request.getParameter("name");
			application.setAttribute("Name", name);
			session.setAttribute("Name", name);
			request.setAttribute("Name", name);
			pageContext.setAttribute("Name", name);
			
			
			String mobileNumber = request.getParameter("mobileNumber");
			application.setAttribute("MobileNumber", mobileNumber);
			session.setAttribute("MobileNumber", mobileNumber);
			request.setAttribute("MobileNumber", mobileNumber);
			
			String email = request.getParameter("email");
			application.setAttribute("Email", email);		
			session.setAttribute("Email", email);
			request.setAttribute("Email", email); */
			
			/*UserDetails userDetails = new UserDetails();
			userDetails.setName(request.getParameter("name"));
			userDetails.setEmail(request.getParameter("email"));
			userDetails.setMobileNumber(request.getParameter("mobileNumber"));
			
			
			pageContext.setAttribute("UserDetails", userDetails);
			request.setAttribute("UserDetails", userDetails);
			session.setAttribute("UserDetails", userDetails);
			application.setAttribute("UserDetails", userDetails); */ 
			
			/* pageContext.setAttribute("UserDetails", userDetails,PageContext.PAGE_SCOPE);
			pageContext.setAttribute("UserDetails", userDetails,PageContext.REQUEST_SCOPE);
			pageContext.setAttribute("UserDetails", userDetails,PageContext.SESSION_SCOPE);
			pageContext.setAttribute("UserDetails", userDetails,PageContext.APPLICATION_SCOPE); */
			
			//response.sendRedirect("Third.jsp");
			
			
			/* UserDetails userDetails = new UserDetails();
			userDetails.setName(request.getParameter("name"));
			userDetails.setEmail(request.getParameter("email"));
			userDetails.setMobileNumber(request.getParameter("mobileNumber"));
			application.setAttribute("UserDetails", userDetails); */
			
			RequestDispatcher rd = request.getRequestDispatcher("Third.jsp");
			rd.forward(request, response);
		%>
	</body>
</html>