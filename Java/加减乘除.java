import java.util.*;
public class ¼Ó¼õ³Ë³ý {
	public static void main(String[] args) {
		System.out.println("input two numbers:");
		Scanner in = new Scanner(System.in);
		int a[] = new int[2];
		int i;
		for (i = 0; i < 2; i++){
			a[i] = in.nextInt();
		}
		System.out.println(a[0] + " + " + a[1] + " = " + (a[0] + a[1]));
	}
}