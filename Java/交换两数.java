import java.util.*;

public class �������� {
	public static void main(String[] args) {
		System.out.println("input two numbers");
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		System.out.println("a = " + a + " b = " + b);
		System.out.println("exchange in main()");

		int t = a;
		a = b; 
		b = t;
		System.out.println("a = " + a + " b = " + b);

		System.out.println("exchange in the same class, but not in mian");
		�������� t1 = new ��������();
		t1.exchange(a, b);
		System.out.println("a = " + a + " b = " + b);

		System.out.println("exchange a different class");
		shit t2 = new shit();
		t2.exchange(a, b);
		System.out.println("a = " + a + " b = " + b);

		System.out.println("so the invoke of function only convel variable's value");
	}

	void exchange(int a, int b) {
		int t = a;
		a = b; 
		b = t;
	}
}

class shit {
	void exchange(int a, int b) {
		int t = a;
		a = b; 
		b = t;
	}
}