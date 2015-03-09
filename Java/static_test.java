public class static_test {
	public static void main(String[] args) {
		Employee[] staff = new Employee[3];
		staff[0] = new Employee("tom", 2222);
		staff[1] = new Employee("xiomg", 124124);
		staff[2] = new Employee("zhang", 889678);

		for (int i = 0; i < 3; i++) { 
			staff[i].setId();
		}
		for (Employee e : staff) {
			System.out.println("name = " + e.getName() + ", id = " + e.getId() + ", salary = " + e.getSalary());
		}

		int n = Employee.getNextId();
		System.out.println("next id = " + n);
	}
}

class Employee {
	private static int nextId = 1;//////static

	private String name;
	private double salary;
	private int id;

	public Employee(String n, double s) {
		name = n;
		salary = s;
		id = 0;
	}

	public String getName() {
		return name;
	}
	public double getSalary() {
		return salary;
	}
	public int getId() {
		return id;
	}

	public void setId() {
		id = nextId;
		nextId++;
	}
	public static int getNextId() {
		return nextId;
	}
/*	public static void main(String[] args) {
		Employee e = new Employee("harry", 5000);
		System.out.println(e.getName() + " " + e.getSalary());
	}*/
}