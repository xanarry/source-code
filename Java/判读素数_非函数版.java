import java.util.*;

public class ÅĞ¶ÁËØÊı_·Çº¯Êı°æ {
	public static void main(String[] args) {
		System.out.print("input a number:");
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();

		boolean flag = true;
		if (n < 2)
			flag = false;
		else {
			for (int i = 2; i <= Math.sqrt(n); i++) {
				if (n%i == 0) {
					flag = false;
					break;
				}
			}
		}

		if (flag)
			System.out.println("YES");
		else
			System.out.println("NO");
	}
}