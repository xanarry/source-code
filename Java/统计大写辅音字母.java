import java.util.*;

public class ͳ�ƴ�д������ĸ {
	public static void main(String[] args) {
		System.out.print("input a String:");
		Scanner in = new Scanner(System.in);
		String str = in.nextLine();

		final char[] consonant = {'A', 'E', 'I', 'O', 'U'};
		int len = str.length();
		int _count = 0; 
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < consonant.length; j++) {
				if (str.charAt(i) == consonant[j])
					_count++;
			}
		}
		System.out.println(len-_count);
	}
}