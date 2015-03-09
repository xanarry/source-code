interface Tea {
	public int getPay();
	public void setPay(int p);
}

interface Stu {
	public int getFee();
	public void setFee(int f);
}

class Student implements Stu {
	private String name;
	private char sex;
	private int age;
	private int fee;

	public Student(String n, char s, int a, int f) {
		name = n;
		sex = s;
		age = a;
		fee = f;
	}
	public void display() {
		System.out.println("name = " + name + "\nsex = " + sex + "\nage = " + age + "\nfee = " + fee);
	}
	public int getFee() {
		return fee;
	}
	public void setFee(int f) {
		fee = f;
	}
}

class Teacher implements Tea {
	private String name;
	private char sex;
	private int age;
	private int pay;

	public Teacher(String n, char s, int a, int p) {
		name = n;
		sex = s;
		age = a;
		pay = p;
	}
	public void display() {
		System.out.println("name = " + name + "\nsex = " + sex + "\nage = " + age + "\npay = " + pay);
	}

	public void setPay(int p) {
		pay = p;
	}
	public int getPay() {
		return pay;
	}
}

class Doctor extends Student implements Tea{
	private int pay;

	public Doctor(String n, char s, int a, int f, int p) {
		super(n, s, a, f);
		pay = p;
	}
	public void display() {
		super.display();
		System.out.println("pay = " + pay);
	}

	public int getFee() {
		return super.getFee();
	}
	public void setFee(int f) {
		super.setFee(f);
	}

	public void setPay(int p) {
		pay = p;
	}
	public int getPay() {
		return pay;
	}

}

public class ≤© ø…˙¿‡ {
	public static void main(String[] args) {
		Doctor d = new Doctor("xiongyang", 'F', 20, 5500, 3000);
		d.display();
		System.out.println(d.getFee());
	}
}