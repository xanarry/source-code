import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;


public class 使用fileinputstream读取文件 {
	//以字节方式读取，遇到中文的字符串会输出乱码
	public static void main(String[] args) {
		final String fileName = "test.txt";
		InputStream inputStream = null;
		try {
			inputStream = new FileInputStream(fileName);
			int ch;
			while ((ch = inputStream.read()) != -1) {
				System.out.print((char) ch);
			}
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} finally {
			try {
				inputStream.close();
			} catch (IOException e) {
				System.out.println(e.getMessage());
			}
		}
	}

}
