import java.io.*;
//本程序仅限输入数字字符串
public class 重载字符串相加 {
	public static void main(String[] args) {
		String s1 = "", s2 = "";

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		try {
			System.out.print("input first string: ");
			s1 = in.readLine();
			System.out.print("input second string: ");
			s2 = in.readLine();
		}
		catch (Exception e) {
			System.out.println(e.getMessage());
		}

		int i1 = Integer.parseInt(s1);
		int i2 = Integer.parseInt(s2);

		float f1 = Float.parseFloat(s1);//将字符串理解为数字储存
		float f2 = Float.parseFloat(s2);

		System.out.println("\nresult of add as string is: " + add(s1, s2));
		System.out.println("\nresult of add of integer is: " + add(i1, i2));
		System.out.println("\nresult of add of float is: " + add(f1, f2));
	}

	static String add(String a, String b) {
		return a + b;
	}

	static String add(int a, int b) {
		return String.valueOf(a + b);//将结果转换为字符串
	}

	static String add(float a, float b) {
		return String.valueOf(a + b);
	}
}