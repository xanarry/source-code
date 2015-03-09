import java.util.*;

public class 折半查找 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[] a = {1, 23, 34, 35, 42, 47, 49, 51, 55, 57, 60, 64, 69, 73, 77, 78, 80, 85, 89, 92, 96, 100};
		for (int t : a) {
			System.out.print(t + " ");
		}

		System.out.print("\ninput a number you wanna find:");
		int obj = in.nextInt();
		int l = 0;
		int r = a.length;
		int m = (l + r) / 2;
		int count = 0;
		while (a[m] != obj) {//如果没有找到就继续查找
			count++;//每遍历一个数，次数自加
			if (count == a.length) {
				System.out.println("find nothing");//如果遍历了每个元素都没有找到
				break;
			}

			if (obj > a[m])//如果比中点大，则在右边继续折半查找
				l = m;

			if (obj < a[m])//否则在左边折半查找
				r = m;
			m = (l + r) / 2;
		}
		
		if (count < a.length)//如果找到了
			System.out.println("the index of " + obj + " is " + (m + 1));
	}
}