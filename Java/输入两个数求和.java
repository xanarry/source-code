import java.util.*;
public class 输入两个数求和 {
	public static void main(String[] args) {
		System.out.print("intput calculate times:");
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		while (n > 0) {
			int a = in.nextInt();
			int b = in.nextInt();
			System.out.println("sum = " + (a + b));
			n--;
		}
	}
}