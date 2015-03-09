import java.util.*;

public class 打印菱形 {
	public static void main(String[] args) {
		System.out.print("input length:");
		Scanner in = new Scanner(System.in);
		int len = in.nextInt();
		//上半部分
		for (int i = 0; i < len; i++) {
			for (int j = len - i; j > 0; j--) {
				System.out.print(" ");
			}
			for (int k = 0; k < 2*i - 1; k++) {
				System.out.print("*");
			}
			System.out.println();
		}
		//下半部分
		for (int i = len - 2; i > 0; i--) {
			for (int j = len - i; j > 0; j--) {
				System.out.print(" ");
			}
			for (int k = 0; k < 2*i - 1; k++) {
				System.out.print("*");
			}
			System.out.println();
		}
	}
}