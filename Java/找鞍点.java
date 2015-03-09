import java.util.*;

public class 找鞍点 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input n:");
		int n = in.nextInt();	

		int[][] a = new int[n][n];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = (int)(Math.random() * n * n);
				System.out.printf("%2d ", a[i][j]);
			}
			System.out.println();
		}
		
		int h_index = 0; 
		int v_index = 0;
		boolean flag = false;

		for (int i = 0; i < n; i++) {//从上到下，遍历每行
			h_index = 0;
			for (int j = 0; j < n; j++) {//查找每行
				if (a[i][h_index] < a[i][j]) {//找到每行的最大的数
					h_index = j;//获取该行最大数的下标
				}
			}
			v_index = i;//记录当前行的位置
			for (int k = 0; k < n; k++) {//遍历当前行最大数所在的列
				if (a[v_index][h_index] > a[k][h_index]) {
					v_index = k;//找到行最小的行编号
				}
			}

			if (v_index == i) {//如果行没有变，即行已经是最小
				flag = true;//做好标记
				break;
			}
		}

		if (flag)
			System.out.println("a[" + v_index + "]" + "[" + h_index + "] = " + a[v_index][h_index]);//输出结果
		else
			System.out.println("NO THIS POINT！");
	}	
}