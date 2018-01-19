package pages;
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;



/*

For running

export CLASSPATH="/home/aman/apache-tomcat-8.0.36/lib/servlet-api.jar"


javac -d ./webapps/CommandServlet/WEB-INF/class/ ./webapps/CommandServlet/WEB-INF/src/FirstServlet.java

*/
public class FirstServlet extends HttpServlet
{
	public void init(ServletConfig config)throws ServletException
	{
		System.out.println("Inside init method");	
	}
	protected void doGet(HttpServletRequest req, HttpServletResponse resp)
              throws ServletException,IOException
	{
		System.out.println("Inside doGet method");
		resp.setContentType("text/html");
		try( PrintWriter out = resp.getWriter())
		{
				out.println("<html>");
				out.println("<Title> This is first servlet </Title>");
				out.println("<body>");
				out.println("<h3>Hello Servlet	:	"+Thread.currentThread()+"</h3>");
				out.println("</body>");
				out.println("</html>");		
		}
	}
	public void destroy()
	{
				System.out.println("Inside destroy method");	
	}
}
