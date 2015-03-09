public class ≥ÈœÛ¿‡ {
	public static void main(String[] args) {
		person[] people = new person[3];
		people[0] = new student("xiong", 'F', "software");
		people[1] = new employee("zhong", 'M', "computer", 4500);
		people[2] = new manager("wang", 'F', "software", 6000, 4000);

		for (person p : people) {
			System.out.println(p.getName());
			p.basic_info();
		}

		manager m = new manager("wang", 'F', "softwarE", 6000, 4000);
		m.display();
	}
}

abstract class person {
	String name;
	char sex;
	public abstract void basic_info();
	public person(){}
	public person(String name, char sex) {
		this.name = name;
		this.sex = sex;
	}
	public String getName() {
		return name;
	}
}

class student extends person {
	String major;
	public student(String n, char s, String m) {
		super(n, s);
		major = m;
 	}
 	public void basic_info() {
 		System.out.println("this is a student");
 	}
 	public String getName() {
 		return name;
 	}
 	public String getMajor() {
 		return major;
 	}
}

class employee extends student {
	int salary;
	public employee(String n, char s, String m, int sa) {
		super(n, s, m);
		salary = sa;
	}
	public void basic_info() {
 		System.out.println("this is a employee");
 	}
 	public String getName() {
 		return name;
 	}
 	public String getMajor() {
 		return major;
 	}
 	public int getSalary() {
 		return salary;
 	}
}

class manager extends employee {
	int wellfair;
	public manager(String n, char s, String m, int sa, int b) {
		super(n, s, m, sa);
		wellfair = b;
	}
	public void basic_info() {
 		System.out.println("this is a manager");
 	}
 	public String getName() {
 		return name;
 	}
 	public String getMajor() {
 		return major;
 	}
 	public int getSalary() {
 		return salary;
 	}
 	public int getWellfair() {
 		return wellfair;
 	}
 	public void display() {
 		System.out.println("-----------------");
 		System.out.println("name: " + super.getName());
 		System.out.println("major: " + super.getMajor());
 		System.out.println("salary: " + super.getSalary());
 		System.out.println("bouns: " + wellfair);
 		basic_info();
 	}
}