import java.util.*;

public class ���Լ������С������ {
	public static void main(String[] args) {
		System.out.print("input two numbers:");
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();

		if (a < b) {
			int t = a; 
			a = b;
			b = t;
		}

		int GCD = fun(a, b);
		int LCM = a * b / GCD;

		System.out.println("GCD = " + GCD + "\nLCM = " + LCM);
	}

	static int fun(int m, int n) {
		if (m%n == 0)
			return n;
		else
			return fun(n, m%n);
	}
}
