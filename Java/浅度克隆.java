import java.util.*;

class MyDate implements Cloneable {
	private int year;
	private int month;
	private int day;

	public MyDate(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}

	public void changeDate(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}

	public String toString() {
		return year + "-" + month + "-" + day;
	}
}

class Student implements Cloneable {
	private	String name;
	private char sex;
	protected MyDate birth;

	public Student(String n, char s, MyDate b) {
		name = n;
		sex = s;
		birth = b;
	}

	public String toString() {
		return name + " " + sex + " " + birth;
	}

	public Object clone() {
		Student cloneObject = null;
		try {
			cloneObject = (Student)super.clone();
		} catch(CloneNotSupportedException e) {
			e.printStackTrace();
		}

		return cloneObject;
	}
}

public class ǳ�ȿ�¡ {
	public static void main(String[] args) {
		Student st1 = new Student("xiongyang", 'F', new MyDate(1993, 12, 30));
		System.out.println("st1 = " + st1);

		System.out.println("\nStudent st2 = st1.clone();");
		Student st2 = (Student)st1.clone();
		System.out.println("st2 = " + st2);

		System.out.println("\nchange the value of birth of st2");
		st2.birth.changeDate(1999, 10, 1);
		System.out.println("st2 = " + st2);
		System.out.println("st1 = " + st1);

		System.out.println("\nchange the value of birth of st1");
		st1.birth.changeDate(2020, 10, 1);
		System.out.println("st2 = " + st2);
		System.out.println("st1 = " + st1);
	}
}