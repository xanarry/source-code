import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class 按行复制文件 {

	public static void main(String[] args) {
		String srcFile = null;
		String destFile = null;
		Scanner in = new Scanner(System.in);
		System.out.print("input source file path:");
		srcFile = in.nextLine();
		System.out.print("input destination file path:");
		destFile = in.nextLine();
		
		BufferedWriter writer = null;
		BufferedReader reader = null;
		
		try {
			writer= new BufferedWriter(new FileWriter(destFile));
			reader = new BufferedReader(new FileReader(srcFile));
			String temp = null;
			int lineCount = 1;
			while ((temp = reader.readLine()) != null) {
				writer.write((lineCount++) + ": " + temp);
				writer.newLine();
			}
			
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} finally {
			System.out.println("file copyed seccessful");
			try {
				writer.close();
				reader.close();
			} catch (IOException e) {
				System.out.println(e.getMessage());
			}
		}
	}

}
