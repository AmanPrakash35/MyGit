package pojo;
public class User 
{
	private String name;
	private String password;
	private String email;
	private String mobileNumber;
	public User() {	
	}
	public User(String name, String password, String email, String mobileNumber) {		
		this.name = name;
		this.password = password;
		this.email = email;
		this.mobileNumber = mobileNumber;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
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
	public String getMobileNumber() {
		return mobileNumber;
	}
	public void setMobileNumber(String mobileNumber) {
		this.mobileNumber = mobileNumber;
	}
	
}
