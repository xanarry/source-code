import java.util.*;

public class 十进制到二进制 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input a decimal number:");
		int src = in.nextInt();
		String dest = traslate(src);
		System.out.println(dest);
	}

	static String traslate(int n) {
	/*  方法都一样
		String temp = "";
		
		while (n > 0) {
			/////////将整数转换为字符串的方法
			temp += Integer.toString(n%2);//计算二进制，细节部分
			n /= 2;
		}

		int t = 0;
		char[] str = new char[temp.length()];
		//调整二进制数字的顺序，由反改为正
		for (int i = temp.length() - 1; i >= 0; i--) {
			str[t++] = temp.charAt(i);
		}

		String result = new String(str);
	*/
		//更愉快的方法
		String result = "";
		while (n > 0) {
			result  = Integer.toString(n%2) + result;
			n /= 2;
		}

		return result;
	}
} 