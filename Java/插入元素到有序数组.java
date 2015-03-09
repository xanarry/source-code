import java.util.*;

public class 插入元素到有序数组 {
	public static void main(String[] args) {
		int[] a = new int[15];
		for (int i = 0; i < 10; i++) {
			a[i] = i;
			System.out.print(i + " ");
		}

		Scanner in = new Scanner(System.in);
		System.out.print("\ninput a number you wanna insert:");
		int _new = in.nextInt();

		int index = 10;
		for (int i = 0; i < 10; i++) {
			if (_new < a[i]) {
				index = i;
				break;
			}
		}
		for (int i = 10; i > index; i--) {
			a[i] = a[i - 1];
		}
		a[index] = _new;

		for (int i = 0; i < 11; i++) {
			System.out.print(a[i] + " ");
		}
		System.out.println();
	}
}