import java.util.*;
public class a_person {

	static class person {
		private String name;
		private int age;
		private char sex;
	
		public person(String n, int a, char s) {
			name = n;
			age = a;
			sex = s;
		}
		public void display() {
			System.out.println("name is " + name);
			System.out.println("age is " + age);
			System.out.println("sex is " + sex);
		}
	
		public void setName() {
			System.out.print("input a name:");
			Scanner in = new Scanner(System.in);
			String n = in.nextLine();
			name = n;
		}
		public void setAge() {
			System.out.print("input a age:");
			Scanner in = new Scanner(System.in);
			int n = in.nextInt();
			age = n;
		}
		public void setSex() {
			System.out.print("input a sex:");
			Scanner in = new Scanner(System.in);
			String n = in.nextLine();
			sex = n.charAt(0);
		}
	
		public String getName() {
			return name;
		}
		public int getAge() {
			return age;
		}
		public char getSex() {
			return sex;
		}
	}

	public static void main(String[] args) {
		System.out.println("now we construct a person object");
		person a = new person("xxx", 21, 'f');
		a.display();

		System.out.println("\nsingle operation");
		a.setName();
		a.setAge();
		a.setSex();
		a.display();

		System.out.println("\nsingle output");
		System.out.println(a.getName());
		System.out.println(a.getAge());
		System.out.println(a.getSex());
	}
}