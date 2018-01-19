package listener;
import javax.servlet.ServletContext;
import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;
import javax.servlet.annotation.WebListener;

import utils.DBUtils;
@WebListener
public class BookShopListener implements ServletContextListener
{
    public BookShopListener() {
    }
    public void contextInitialized(ServletContextEvent e)
    { 
    	try
    	{
			ServletContext context = e.getServletContext();
			Class.forName(context.getInitParameter("DRIVER"));
			DBUtils.setContext(context);
		}
    	catch (ClassNotFoundException ex) 
    	{
			throw new RuntimeException(ex);
		}
    }
    public void contextDestroyed(ServletContextEvent e) 
    {	}	
}
