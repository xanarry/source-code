import java.util.*;

public class ÅĞ¶ÏÊä³öËØÊı {
	public static void main(String[] args) {
		System.out.println("input a range of prime num");
		Scanner in = new Scanner(System.in);
		int start = in.nextInt();
		int end = in.nextInt();
		int count = 0;
		for (int i = start; i <= end; i++) {
			if (isPrime(i)) {
				System.out.print(i + " ");
				count++;

				if (count%5 == 0)
					System.out.println();
			}
		}
	}

	static boolean isPrime(int n) {
		if (n < 2)
			return false;
		for (int i = 2; i <= Math.sqrt(n); i++) {
			if (n%i == 0) {
				return false;
			}
		}
		return true;
	}
}