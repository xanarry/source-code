import java.util.*;
public class ������������������� {
	static int max(int x, int y) {
		if (x > y) {
			return x;
		}
		else
			return y;
	}
	public static void main(String[] args) {
		System.out.println("input 2 numbers:");
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		System.out.println("max of " + a + " " + b + " is " + max(a, b));
	}
}