package filter;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.annotation.WebFilter;
public class TestFilter implements Filter {
    public TestFilter() {
    }    
	public void init(FilterConfig fConfig) throws ServletException {	
	}	
	public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException 
	{
		long before = System.currentTimeMillis();
		chain.doFilter(request, response);
		long after = System.currentTimeMillis();
		try( PrintWriter out = response.getWriter())
		{
			out.println("<br/>Response Time : "+( after-before)+"<br/>");
		}
	}
	public void destroy() {
		// TODO Auto-generated method stub
	}

}
