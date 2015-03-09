import java.util.*;

public class Í³¼Æµ¥´Ê {
	public static void main(String[] args) {
		System.out.println("input a strng:");
		Scanner in = new Scanner(System.in);
		String str = in.nextLine();
		str += " ";

		int wordCount = 0;
		boolean flag = false;

		for (int index = 0; index < str.length(); index++) {
			if (str.charAt(index) != ' ')
				flag = true;
			if (str.charAt(index) == ' ' && flag == true)
			{
				wordCount++;
				flag = false;
			}
		}
		System.out.println("wordCount = " + wordCount);
	}
}