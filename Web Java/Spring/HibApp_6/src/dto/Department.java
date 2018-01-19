package dto;

import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.Id;
import javax.persistence.OneToMany;
import javax.persistence.Table;

@Entity
@Table(name="DEPARTMENT")
public class Department 
{
	private int number;
	private String name;
	private String location;
	private List<Employee> empList;
	public Department() {	
	}
	public Department(int number, String name, String location) {
		this.number = number;
		this.name = name;
		this.location = location;
	}
	@Id
	@Column(name="DEPTNO")
	public int getNumber() {
		return number;
	}
	public void setNumber(int number) {
		this.number = number;
	}
	@Column(name="DNAME")
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	@Column(name="LOC")
	public String getLocation() {
		return location;
	}
	public void setLocation(String location) {
		this.location = location;
	}
	@OneToMany(mappedBy="department", fetch=FetchType.LAZY, cascade={ CascadeType.ALL})
	public List<Employee> getEmpList() {
		return empList;
	}
	public void setEmpList(List<Employee> empList) {
		this.empList = empList;
	}
	@Override
	public String toString() {
		return "Department [number=" + number + ", name=" + name + ", location=" + location + "]";
	}	
}
