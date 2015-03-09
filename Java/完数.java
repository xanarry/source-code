import java.util.*;

public class ÍêÊı {
	public static void main(String[] args) {
		int min;
		int max;
		Scanner in = new Scanner(System.in);
		System.out.println("input range[L, R]:");
		min = in.nextInt();
		max = in.nextInt();
		for (int i = min; i < max; i++) {
			if (factorsum(i) == i)
				System.out.println(i);
		}
	}

	static int factorsum(int n) {
		int sum = 0;
		for (int i = 2; i < n; i++) {
			if (n%i == 0)
				sum += i;
		}
		sum += 1;
		return sum;
	}
}