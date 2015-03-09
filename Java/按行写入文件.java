import java.util.*;
import java.io.*;

public class 按行写入文件 {
	public static void main(String[] args) {
		try {
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			File out = new File("test.txt");
			String temp = null;
			BufferedWriter writer = new BufferedWriter(new FileWriter(out));
			while (!(temp = reader.readLine()).equals("quit")) {
				writer.write(temp);
				writer.newLine();
			}
			reader.close();
			writer.close();
		} catch (Exception e) {
			System.out.println(e.getMessage());
		} 
	}
}