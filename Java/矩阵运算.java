/*
����һ��������repeat (0<repeat<10)����repeat ���������㣺
����1 ��������n(1��n��6), �ٶ���n �׷���a ,
����þ�������Խ��ߡ����һ�к����һ�����������Ԫ��֮��.
(���Խ���Ϊ�Ӿ�������Ͻ������½ǵ�����)
*/
import java.util.*;
public class �������� {
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