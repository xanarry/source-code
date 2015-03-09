import java.util.*;

public class ÅĞ¶Ï»ØÎÄ×Ö·û´® {
	public static void main(String[] args) {
		System.out.println("input a String");
		Scanner in = new Scanner(System.in);
		String str = in.nextLine();

		System.out.println("String you input is " + str);

		if (isHuiwen1(str))
			System.out.println("it is huiwen");
		else 
			System.out.println("it is not huiwen");

		if (isHuiwen2(str))
			System.out.println("it is huiwen");
		else 
			System.out.println("it is not huiwen");

		if (isHuiwen3(str))
			System.out.println("it is huiwen");
		else 
			System.out.println("it is not huiwen");
			
		if (isHuiwen4(str))
			System.out.println("it is huiwen");
		else 
			System.out.println("it is not huiwen");
	}

	static boolean isHuiwen1(String a) {
		int start = 0;
		int end = a.length() - 1;
		while (a.charAt(start) == a.charAt(end)) {	
			if (start >= end)
				return true;

			start++;
			end--;
		}
		return false;
	}

	static boolean isHuiwen2(String a) {
		int len = a.length();
		int i;
		for (i = 0; i < len/2;) {
			if (a.charAt(i) == a.charAt(len - 1 - i))
				i++;
			else 
				break;
		}
		if (i == len/2)
			return true;
		else
			return false;
	}

	static boolean isHuiwen3(String a) {
		int len = a.length();
		String head = a.substring(0, len/2);
		char[] temp = new char[len/2];
		for (int i = 0; i < len/2; i++) {
			temp[i] = a.charAt(len - 1 - i);
		}
		String tail = new String(temp);
		if (head.equals(tail))
			return true;
		else
			return false;
	}

	static boolean isHuiwen4(String a) {
		int start = 0;
		int end = a.length() - 1;
		while (start < end) {
			if (a.charAt(start) != a.charAt(end)) {
				return false
			}
			else {
				start++;
				end--;
			}
		}
		return true;
	}
}