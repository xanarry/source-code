/*
输入一个正整数repeat (0<repeat<10)，做repeat 次下列运算：
读入1 个正整数n(1≤n≤6), 再读入n 阶方阵a ,
计算该矩阵除副对角线、最后一列和最后一行以外的所有元素之和.
(副对角线为从矩阵的右上角至左下角的连线)
*/
import java.util.*;
public class 矩阵运算 {
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
		
		int sum = 0; 
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (i + j != n - 1) {
					sum += a[i][j];
				}
			}
		}
		System.out.println("sum = " + sum);
	}
}