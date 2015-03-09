import java.util.*;
public class labelbreak {
	public static void main(String[] args) {
		int i = 0;
		int n = 0;
		Scanner in = new Scanner(System.in);
		input:
		while (i < 5) {
			System.out.println("input a number:");
			n = in.nextInt();
			if (n < 0)
				break input;
			i++;
		}

		if (n < 0)
			System.out.println("you mast has input more than 5 times");
		if (n > 0)
			System.out.println("you input " + n);
		in.close();
	}
}