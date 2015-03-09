import java.io.*;
import java.util.*;

public class ���ַ���ȡ�ļ� {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input file path: ");
		String inFile = in.nextLine();

		FileReader reader = null;
		PrintWriter writer = null;

		try {
			reader = new FileReader(inFile);
			writer = new PrintWriter(System.out);//�ڿ���̨�������

			char buffer[] = new char[512];
			int getLen = 0;

			while ((getLen = reader.read(buffer)) != -1) {
				writer.write(buffer, 0, getLen);
			}

		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} catch (NullPointerException e) {
			System.out.println(e.getMessage());
		} finally {
			try {
				writer.close();
				reader.close();
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
		}
	}
}