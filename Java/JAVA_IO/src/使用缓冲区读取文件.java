import java.io.FileInputStream;
import java.io.IOException;


public class 使用缓冲区读取文件 {

	public static void main(String[] args) {
		final String fileName = "test.txt";
		FileInputStream fileInputStream = null;
		try {
			fileInputStream = new FileInputStream(fileName);
			byte[] buffer = new byte[512];
			int len = 0;
			while ((len = fileInputStream.read(buffer)) != -1) {
				System.out.write(buffer, 0, len);
			}
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} finally {
			try {
				fileInputStream.close();
			} catch (IOException e) {
				System.out.println(e.getMessage());
			}
		}

	}

}
