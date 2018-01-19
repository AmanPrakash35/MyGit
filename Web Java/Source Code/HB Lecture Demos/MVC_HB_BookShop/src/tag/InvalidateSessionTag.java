package tag;

import java.io.IOException;

import javax.servlet.http.HttpSession;
import javax.servlet.jsp.JspException;
import javax.servlet.jsp.PageContext;
import javax.servlet.jsp.tagext.SimpleTagSupport;

public class InvalidateSessionTag extends SimpleTagSupport
{	public InvalidateSessionTag() {		
	}
	@Override
	public void doTag() throws JspException, IOException {		
		PageContext pageContext =  (PageContext) this.getJspContext();			
		HttpSession session = pageContext.getSession();
		session.invalidate();
	}
}
