import java.util.*;
public class º∆À„ ±º‰≤Ó {
	public static void main(String[] args) {
		System.out.print("start from:");
		Scanner in = new Scanner(System.in);
		String start = in.nextLine();
		System.out.print("end at:");
		String end = in.nextLine();

		String[] a = new String[2];
		a = start.split(":");
		String[] b = new String[2];
		b = end.split(":");

		int h1 = Integer.parseInt(a[0]);
		int m1 = Integer.parseInt(a[1]);

		int h2 = Integer.parseInt(b[0]);
		int m2 = Integer.parseInt(b[1]);

		int tm = m2 - m1;
		if (tm < 0) {
			tm += 60;
			h2 -= 1;
		}
		int th = h2 - h1;
		String result = new String(th + ":" + tm);

		System.out.println(end + " - " + start + " = " + result);
	}
}