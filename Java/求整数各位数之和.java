import java.util.*;

public class ��������λ��֮�� {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input a number:");
		int num = in.nextInt();
		int result = 0;
		while (num > 0) {
			result += num%10;
			num /= 10;
		}
		System.out.println(result);
	}
}