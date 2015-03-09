import java.util.*;

public class 计算子串出现的次数 {
	public static void main(String[] args) {
		System.out.print("input a String:");
		Scanner in = new Scanner(System.in);
		String str = in.nextLine();
		System.out.print("input sub String:");
		String sub_str = in.nextLine();
		int show_time = 0; 
		int len = sub_str.length();
		for (int i = 0; i <= str.length() - len; i++) {
			//substring(start,end),截取字符串，equals比较字符串
			if (str.substring(i, i + len).equals(sub_str))
				show_time++;
		}
		System.out.println("sub_str show " + show_time + " time");
	}
}