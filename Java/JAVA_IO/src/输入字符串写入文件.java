import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;

public class 输入字符串写入文件 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input destination file name:");
		String filename  = in.nextLine();
		System.out.println("input the content you'll wirte into:");
		String content = in.nextLine();
		Writer writer = null;
		in.close();
		try {
			writer = new FileWriter(filename);
			writer.write(content);
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} finally {
			try {
				writer.close();
			} catch (Exception e2) {
				System.out.println(e2.getMessage());
			}
		}
	}
}
