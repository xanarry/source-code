import java.util.*;

public class 约瑟夫环 {
	public static void main(String[] args) {
		System.out.print("input number of people:");
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		System.out.print("input quit number:");
		int quit = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = 1;
		}

		int index = 0;
		int count = 1;//用于报数
		int p = n;//跟踪剩余人数

		while (p > 1) {//剩余人数大于1，继续报数
			if (a[index] == 1) {//如果当前位置有人
				count++;
				if (count == quit) {
					a[index] = 0;//报到m出局
					count = 1;//报到m出局
					p--;//人数减1
				}
			}
			if (++index == n)//循环数组
				index = 0;
		}

		for (int i = 0; i < n; i++) {
			if (a[i] != 0)
				System.out.println("the last one still remain is " + i);
		}
	}
}
