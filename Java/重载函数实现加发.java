import java.util.*;

public class 重载函数实现加发 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("input two String:");
		String a = in.nextLine();
		String b = in.nextLine();
		System.out.println(a + " + " + b + " = " + add(a, b));

		System.out.println("input two integer:");
		int c = in.nextInt();
		int d = in.nextInt();
		System.out.println(c + " + " + d + " = " + add(c, d));

		System.out.println("input two float:");
		float e = in.nextFloat();
		float f = in.nextFloat();
		System.out.println(e + " + " + f + " = " + add(e, f));
	}

	static String add(String a, String b) {
		return a + b;
	}

	static int add(int a, int b) {
		return a + b;
	}

	static float add(float a, float b) {
		return a + b;
	}
}