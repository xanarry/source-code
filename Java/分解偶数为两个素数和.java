import java.util.*;

public class �ֽ�ż��Ϊ���������� {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n;
		do {
			System.out.print("input:");
			n = in.nextInt();//�����n�������������Ϊͨ��sqrt���������������С��Ҫ3
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