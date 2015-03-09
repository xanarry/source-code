import java.io.*;
import java.util.*;

public class 按行读取文件 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input a file name: ");
		String fileName = in.nextLine();
		System.out.print("input destination file: ");
		String destfileName = in.nextLine();

		Reader reader = null;
		FileWriter writer = null;
		BufferedReader bufferedReader= null;

		try {
			reader = new FileReader(new File(fileName));
			writer = new FileWriter(destfileName);//第二个参数用于确定是否追加文件，默认为false，可以不写上
			bufferedReader = new BufferedReader(reader);

			int count = 0;
			String temp;
			writer.write("这是转移文件过来的内容:\n");
			while ( (temp = bufferedReader.readLine()) != null) {
				temp = (count + 1) + ":  " + temp;
				System.out.println(temp);
				writer.write(temp + '\n');
				count++; 
			}
			System.out.println("totally has " + count + " lines");
		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} finally {
			try {
				reader.close();
				bufferedReader.close();
				writer.close();
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
		}
	}
}