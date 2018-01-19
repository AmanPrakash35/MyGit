package beans;

import java.util.Set;

import dao.BookDao;

public class SubjectBean
{
	private BookDao dao;
	private Set<String> subjects;
	public SubjectBean() throws Exception{
		this.dao = new BookDao();
	}
	public Set<String> getSubjects() {
		return subjects;
	}
	public void setSubjects(Set<String> subjects) {
		this.subjects = subjects;
	}
	public void fetchSubjects()throws Exception
	{
		 this.subjects = this.dao.getSubjects();
	}
	public void closeDao()throws Exception
	{
		this.dao.close();
	}
}
