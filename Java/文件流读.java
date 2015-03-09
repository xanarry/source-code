import java.io.*;

public class ÎÄ¼þÁ÷¶Á {
	public static void main(String[] args) throws Exception {
		File f = new File("test.txt");
		Reader reader = null;
		reader = new InputStreamReader(new FileInputStream(f));
		char[] ch = new char[100];
		int len = reader.read(ch);
		reader.close();
		System.out.println(new String(ch, 0, len));
	}
}