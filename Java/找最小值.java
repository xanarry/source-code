import java.util.*;

public class ÕÒ×îĞ¡Öµ {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input repeat times:");
		int times = in.nextInt();

		int i = 0;
		while (i < times) {
			System.out.println("now you can input fore numbers");

			int min = in.nextInt();
			for (int j = 1; j < 4; j++) {
				int temp = in.nextInt();
				if (temp < min)
					min = temp;
			}
			
			System.out.println("the min of this couple is " + min);
			i++;
		}
	}
}