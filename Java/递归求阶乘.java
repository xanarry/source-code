import java.util.*;

public class µİ¹éÇó½×³Ë {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input a number:");
		long n = in.nextInt();
		long result = fac(n);
		System.out.println(n + "! = " + result);
	}

	static long fac(long n) {
		if (n > 2)
			return n * fac(n - 1);
		else
			return n;
	}

}