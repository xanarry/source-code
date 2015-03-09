import java.util.*;

public class 输入数中的最大最小数 {
	public static void main(String[] args) {
		System.out.print("input the length of the array:");
		Scanner in = new Scanner(System.in);
		int len = in.nextInt();
		int[] a = new int[len];
		System.out.println("input " + len + " numbers:");
		for (int i = 0; i < len; i++) {
			a[i] = in.nextInt();
		}

		int max = a[0];
		int min = a[0];

		for (int temp : a) {
			if (temp > max)
				max = temp;
			if (temp < min)
				min = temp;
		}

		System.out.println("max of you input is " + max);
		System.out.println("min of you input is " + min);
	}
}