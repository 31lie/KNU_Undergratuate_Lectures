//2020114658 이윤서
// 본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.
import java.util.Scanner;

class Employee{
	//private 변수 설정
	private String firstname, lastname;
	private double monthly_salary;
	
	//생성자
	public Employee(String firstname, String lastname, double monthly_salary) {
		this.firstname = firstname;
		this.lastname = lastname;
		if (monthly_salary>0.0) {
			this.monthly_salary = monthly_salary;
		}
	}
	
	public String getFirstname() {
		return firstname;
	}
	public String getLastname() {
		return lastname;
	}
	public double getMonthlySalary() {
		return monthly_salary;
	}
	
}

public class EmployeeTest {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		String firstname, lastname;
		double monthly_salary;
		
		System.out.print("Enter first name: ");
		firstname = input.nextLine();
		System.out.print("Enter last name: ");
		lastname = input.nextLine();
		System.out.print("Enter monthly salary: ");
		monthly_salary = input.nextDouble();
		Employee E1 = new Employee(firstname, lastname, monthly_salary);
		
		input.nextLine();
		
		System.out.print("Enter first name: ");
		firstname = input.nextLine();
		System.out.print("Enter last name: ");
		lastname = input.nextLine();
		System.out.print("Enter monthly salary: ");
		monthly_salary = input.nextDouble();
		Employee E2 = new Employee(firstname, lastname, monthly_salary);
		
		input.nextLine();
		
		System.out.println("Employee 1: " + E1.getFirstname()+E1.getLastname()+"; Yearly Salary: "+ E1.getMonthlySalary()*12);
		System.out.println("Employee 2: " + E2.getFirstname()+E2.getLastname()+"; Yearly Salary: "+ E2.getMonthlySalary()*12);
		
		System.out.println("\nIncreasing employee salaries by 10%");
		System.out.println("Employee 1: " + E1.getFirstname()+E1.getLastname()+"; Yearly Salary: "+ E1.getMonthlySalary()*12*1.1);
		System.out.println("Employee 2: " + E2.getFirstname()+E2.getLastname()+"; Yearly Salary: "+ E2.getMonthlySalary()*12*1.1);
		
		input.close();
	} 

}
