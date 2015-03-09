import java.util.*;

class Student implements Cloneable {
	private String name;
	private char sex;
	private Date birth;

	public Student(String n, char s) {
		name = n;
		sex = s;
		birth = new Date();
	}

	public String toString() {
		return name + " " + sex + " " + birth;
	}

	public void setName(String n) {
		name = n;
	}

	public Object clone() {
		Student returnClass = null;
		try {
			returnClass = (Student)super.clone();
		} catch(CloneNotSupportedException e) {
			 e.printStackTrace();
		}
		return returnClass;
	} 
}

public class ¶ÔÏó¿ËÂ¡ {
	public static void main(String[] args) {
		Student a = new Student("xiongyang", 'F');
		System.out.println("a = " + a);

		Student b = a;
		System.out.println("b = " + b);

		System.out.println("\nusing '=' and change the value of a");
		a.setName("changed");
		System.out.println("a = " + a);
		System.out.println("b = " + b);

		System.out.println("\nusing \"clone\" and change the value of a");
		a.setName("xiongyang");
		System.out.println("a = " + a);

		System.out.println("cloned");
		b = (Student)a.clone();

		System.out.println("changed a");
		a.setName("changed");

		System.out.println("a = " + a);
		System.out.println("b = " + b);
	}
}