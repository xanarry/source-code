import java.io.*;

public class ÎÄ¼þÁ÷Ð´ {
	public static void main(String[] args) throws Exception {
		File f = new File("test.txt");
		Writer out = new OutputStreamWriter(new FileOutputStream(f));
		out.write("hello world");
		out.close();		
	}
}