import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class writer向文件追加内容 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input file path:");
		String fileName = in.nextLine();
		
		FileWriter writer = null;
		try {
			writer = new FileWriter(fileName, true);
			
			for (int i = 100; i < 1000; i++) {
				writer.write(String.valueOf(i) + "\n");
			}
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} finally {
			try {
				writer.close();
			} catch (IOException e) {
				System.out.println(e.getMessage());
			}
		}
	}

}
