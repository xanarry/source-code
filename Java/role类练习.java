abstract class Role {
	private String name;
	private char sex;
	private int age;

	public Role(String name, char sex, int age) {
		this.name = name;
		this.sex = sex;
		this.age = age;
	}

	public void setName(String name) {
		this.name = name;
	}
	public void setSex(char sex) {
		this.sex = sex;
	}
	public void setAge(int age) {
		this.age = age;
	}

	public String getName() {
		return this.name;
	}
	public char getSex() {
		return this.sex;
	}
	public int getAge() {
		return this.age;
	}

	abstract public void show();
}

class Employee extends Role {
	private int salary;
	private static int ID = 0;

	public Employee(String name, char sex, int age, int salary) {
		super(name, sex, age);
		this.salary = salary;
		++ID;
	}

	public void show() {
		System.out.println("name = " + super.getName());
		System.out.println("sex = " + super.getSex());
		System.out.println("age = " + super.getAge());
		System.out.println("salary = " + salary);
		System.out.println("ID = " + ID);
	}
}

class Manager extends Employee {
	final int bonds = 100;

	public Manager(String name, char sex, int age, int salary) {
		super(name, sex, age, salary);
	}

	public void show() {
		super.show();
		System.out.println("bonds = " + bonds);
	}
}

public class role¿‡¡∑œ∞ {
	public static void main(String[] args) {
		System.out.println("Employee");
		Employee em = new Employee("xiong", 'F', 20, 7000);
		em.show();

		System.out.println("\nManager");
		Manager ma = new Manager("xanarry", 'F', 20, 10000);
		ma.show();
	}	
}