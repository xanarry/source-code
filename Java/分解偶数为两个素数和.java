import java.util.*;

public class 分解偶数为两个素数和 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n;
		do {
			System.out.print("input:");
			n = in.nextInt();//输入的n必须大于六，因为通过sqrt计算出来的输入最小都要3
		}
		while (n%2 != 0 || n < 6);

		for (int i = 2; i < n/2; i++) {
			if (isPrime(i) && isPrime(n - i)) {
				System.out.println(n + " = " + i + " + " + (n - i));
			}
		}
	}

	static boolean isPrime(int n) {
		if (n < 2)
			return false;
		if (n == 3)
			return true;
		for (int i = 2; i <= Math.sqrt(n); i++) {
			if (n % i == 0)
				return false;
		}
		return true;
	}
}