import java.io.*;

public class ÎÄ±¾¶ÁÐ´ {
	public static void main(String[] args) throws Exception {
		FileWriter out = new FileWriter("test.txt");
		out.write("hello java");
		out.close();

		char[] ch = new char[100];
		FileReader in = new FileReader("test.txt");
		int len = in.read(ch);
		System.out.println(new String(ch, 0, len));
		in.close();
	}
}