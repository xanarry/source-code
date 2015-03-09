import java.io.FileWriter;
import java.io.IOException;


public class 将计算过程写入文件 {

	public static void main(String[] args) {
		FileWriter fileWriter = null;
		double pi=2;
		long  i;
		try {
			fileWriter = new FileWriter("1111.txt");
			for(i = 100000; i >= 1; i--) {
				pi = pi * (double) i / ( 2 * i + 1 ) + 2;
				fileWriter.write(String.valueOf(pi) + "\n");
			}
		} catch (IOException e) {
			e.getStackTrace();
		} finally {
			try {
				fileWriter.close();
			} catch (IOException e) {
				System.out.println(e.getMessage());
			}
		}
	}
}
