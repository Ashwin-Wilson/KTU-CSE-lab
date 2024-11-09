import java.util.*;
class Employeee{
	Scanner sc = new Scanner(System.in);	
	String name;
	String address, phNumber;
	int age, salary;
	Employeee(){
		System.out.println("Enter name  : ");
		name = sc.nextLine();
		System.out.println("Enter age  : ");
		age = sc.nextInt();
		sc.nextLine();
		System.out.println("Enter Phone number  : ");
		phNumber = sc.nextLine();
		System.out.println("Enter address : ");
		address = sc.nextLine();
		System.out.println("Enter salary: ");
		salary = sc.nextInt();
	}
	void printSalary(){
		System.out.println("\n salary: "+salary);
	}
}
class Officer extends Employeee{
	String specialization;
	String department;
	Officer(){
		sc.nextLine();
		System.out.println("Enter specialization : ");
		specialization = sc.nextLine();
		
		System.out.println("Enter department : ");
		department = sc.nextLine();
	} 
}
class Manager extends Employeee{
	String specialization;
	String department;
	Manager(){
		sc.nextLine();
		System.out.println("Enter specialization : ");
		specialization = sc.nextLine();	
		System.out.println("Enter department : ");
		department = sc.nextLine();
	}
}
class EmployeeImplement{
	public static void main(String arr[]){
	
		Officer off = new Officer();
		Manager mng = new Manager();
		System.out.println("\nOfficer :\n");
		System.out.println("Name : "+off.name+"\nAge : "+off.age+"\nPh.No :"+off.phNumber+"\nSalary : "+off.salary+"\nAddress : "+off.address+
		"\nSpecialization : "+off.specialization+"\nDepartment : "+off.department);
		System.out.println("\nManager :\n");
		System.out.println("Name : "+mng.name+"\nAge : "+mng.age+"\nPh.No :"+mng.phNumber+"\nSalary : "+mng.salary+"\nAddress : "+mng.address+
		"\nSpecialization : "+mng.specialization+"\nDepartment : "+mng.department);	
	}
}
