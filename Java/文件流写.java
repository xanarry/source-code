import java.io.*;

public class �ļ���д {
	public static void main(String[] args) throws Exception {
		File f = new File("test.txt");
		Writer out = new OutputStreamWriter(new FileOutputStream(f));
		out.write("hello world");
		out.close();		
	}
}