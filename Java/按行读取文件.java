import java.io.*;
import java.util.*;

public class ���ж�ȡ�ļ� {
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
			writer = new FileWriter(destfileName);//�ڶ�����������ȷ���Ƿ�׷���ļ���Ĭ��Ϊfalse�����Բ�д��
			bufferedReader = new BufferedReader(reader);

			int count = 0;
			String temp;
			writer.write("����ת���ļ�����������:\n");
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