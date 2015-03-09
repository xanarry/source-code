import java.util.*;

public class 移动数组元素 {
	public static void main(String[] args) {
		int[] a = {1, 23, 34, 35, 42, 47, 49, 51, 55, 57, 60, 64, 69, 73, 77, 78, 80, 85, 96, 100};
		for (int t : a) {
			System.out.print(t + " ");
		}
		System.out.print("\ninput how many units you wanna move this array:");
		Scanner in = new Scanner(System.in);
		int units = in.nextInt();
		for (int i = 0; i < units; i++) {//移动units这么多位置
			int t = a[a.length - 1];
			for (int j = a.length - 1; j > 0; j--) {//移动数组元素
				a[j] = a[j - 1];
			}
			a[0] = t;
		}
		for (int t : a) {
			System.out.print(t + " ");
		}
		System.out.println();
	}
}