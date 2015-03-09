import java.util.*;
import java.lang.*;

public class 统计字母空格数字和其它字符的个数 {
	public static void main(String[] args) {
		System.out.print("input a String:");
		Scanner in = new Scanner(System.in);
		String str = in.nextLine();

		int letter = 0;
		int number = 0;
		int other = 0;

		for (int i = 0; i < str.length(); i++) {
			if (Character.isDigit(str.charAt(i)))
				number++;
			else if (Character.isLetter(str.charAt(i)))
				letter++;
			else
				other++;
		}

		System.out.println("Digit: " + number);
		System.out.println("Letter: " + letter);
		System.out.println("Other: " + other);
	}
}