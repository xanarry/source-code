import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;


public class 按行读取文件 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input file path:");
		String filename = in.nextLine();
		File file = new File(filename);
		if (!file.exists()) {
			System.out.println("file is not exist");
			System.exit(0);
		} else {
			if (!file.canRead()) {
				System.out.println("file is not readable");
				System.exit(0);
			}
		}
		
		BufferedReader bufferedReader = null;
		FileReader fileReader = null;
		
		try {
			bufferedReader = new BufferedReader(new FileReader(filename));
			int lineCount = 1;
			String temp;
			while ((temp = bufferedReader.readLine()) != null) {
				System.out.println(lineCount + ": " + temp);
				lineCount++;
			}
		} catch (IOException e) {
			System.out.println("line 37: " + e.getMessage());
		} finally {
			try {
				fileReader.close();
				bufferedReader.close();
			} catch (Exception e2) {
				e2.getStackTrace();
			}
		}

	}

}
