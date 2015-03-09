import java.util.*;

public class 输出数字的位数和各位数字 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input a number:");
		long num = in.nextInt();
		String snum = String.valueOf(num);
		int len = snum.length();
		System.out.println("length = " + len);
		for (int i = 0; i < len; i++) {
			System.out.print(snum.charAt(i) + " ");
		}
		System.out.println();
	}
}