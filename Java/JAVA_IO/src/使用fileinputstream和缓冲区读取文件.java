import java.io.FileInputStream;
import java.io.IOException;


public class 使用fileinputstream和缓冲区读取文件 {

	public static void main(String[] args) {
		final String fileName = "test.txt";
		FileInputStream fileInputStream = null;
		try {
			fileInputStream = new FileInputStream(fileName);
			byte[] buffer = new byte[512];
			while (fileInputStream.read(buffer) != -1) {
				System.out.write(buffer);
				
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
