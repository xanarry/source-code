abstract class person {
	private String name;
	private int age;
	private char sex;

	public person() {
		name = "null";
		age = 0;
		sex = 'F';
	}
	public person(String n, int a, char s) {
		name = n;
		age = a;
		sex = s;
	}	
	public void showMe() {
		System.out.println("name:" + name + "\nage:" + age + "\nsex:" + sex);
	}
	public abstract void study(String stuff);
}

interface program {
	public void program(String stuff);
}

class programer extends person implements program {
	private String codingType;
	public programer()
	{
		codingType = "c++";
	}
	public programer(String n, int a, char s, String t) {
		super(n, a, s);
		codingType = t;
	}
	public void showMe() {
		super.showMe();
		System.out.println("codingType:" + codingType);
	}
	public void study(String stuff) {
		System.out.println("i was stupid and i am studing " + stuff);
	}
	public void program(String stuff) {
		System.out.println("recent, i'm writing some program for a girl, hahaaaaaa, it is " + stuff);
	}
}

public class a_grogrammer {
	public static void main(String[] args) {
		System.out.println("defualt setting");
		programer a = new programer();
		a.showMe();
		a.study("java");
		a.program("ic card");

		System.out.println("\nset user's info");
		programer b = new programer("xanarry", 20, 'F', "c++");
		b.showMe();
		b.study("java");
		b.program("hello women");
	}
}