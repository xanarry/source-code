import java.util.*;

public class 输入三个数由小到大输出 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input three numbers: ");
		int a, b, c, t;

		a = in.nextInt();
		b = in.nextInt();
		c = in.nextInt();

		System.out.printf("a = %d\nb = %d\nc = %d\n", a, b, c);

		if (a < b) {
			t = a;
			a = b;
			b = t;
		}
		
		if (a < c) {
			t = a; 
			a = c; 
			c = t;
		}

		if (b < c) {
			t = b;
			b = c;
			c = t;
		}
		System.out.printf("\na = %d\nb = %d\nc = %d\n", a, b, c);		
	}
}