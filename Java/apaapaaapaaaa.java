import java.util.*;

public class apaapaaapaaaa {
	public static void main(String[] args) {
		long result = 0;
		int a;
		int n;
		Scanner in = new Scanner(System.in);
		System.out.print("input a:");
		a = in.nextInt();
		System.out.print("input n:");
		n = in.nextInt();
		int i = 0; 
		int t = a;
		while (i < n) {
			result += t;
			t = t*10 + a;
			i++;
		}
		System.out.println("result = " + result);
	}
}