package listener;
import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;
import javax.servlet.annotation.WebListener;

import utils.HBUtils;

@WebListener
public class BookShopListener implements ServletContextListener 
{
    public BookShopListener() {        
    }
    public void contextInitialized(ServletContextEvent e)  
    { 
    	HBUtils.getSessionFactory();
    }
    public void contextDestroyed(ServletContextEvent e)
    {	
    	HBUtils.getSessionFactory().close();
    }	
}
