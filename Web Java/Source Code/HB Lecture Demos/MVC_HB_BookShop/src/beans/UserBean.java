package beans;

import java.io.Serializable;

import dao.UserDao;
import pojo.User;
public class UserBean  implements Serializable
{
	private static final long serialVersionUID = 2462582538355598128L;
	private String userName;
	private String password;
	private String email;
	private String contactNumber;
	private String message;
	
	private UserDao dao;
	public UserBean() throws Exception{
		this.dao = new UserDao();
	}
	public String getUserName() {
		return userName;
	}
	public void setUserName(String userName) {
		this.userName = userName;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	public String getEmail() {
		return email;
	}
	public void setEmail(String email) {
		this.email = email;
	}
	public String getContactNumber() {
		return contactNumber;
	}
	public void setContactNumber(String contactNumber) {
		this.contactNumber = contactNumber;
	}
	public String getMessage() {
		return message;
	}
	public void setMessage(String message) {
		this.message = message;
	}
	public String registerUser( )throws Exception
	{
		User user = new User(userName, password, email, contactNumber);
		this.dao.registerNewUser(user);
		message = "User registration is successful.";
		return "Index";
	}
	public String validateUser( )throws Exception
	{
		User user = this.dao.authenticateUser(userName, password);
		if( user == null )
		{
			message = "Invalid username or password";
			return "Index";
		}
		message = "Login is successful";
		return "Subject";
	}
}
