import java.util.*;
import java.lang.*;
public class ×ÖÄ¸×ª»» {
	public static void main(String[] args) throws Exception {
		char ch = (char)System.in.read();
		while (ch != '!') {
			if (Character.isLowerCase(ch))
				ch = (char)(ch - 32);
			else if (Character.isUpperCase(ch))
				ch = (char)(ch + 32);

			System.out.print(ch);
			ch = (char)System.in.read();
		}
		System.out.println();
	}
}