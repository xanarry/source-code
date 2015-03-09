import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class ���̶���д���ļ����� {
	/*
	 * ʹ��bufferedReader��bufferedWriter,ֱ�����ļ���д��ÿ��������ַ���
	 */
	public static void main(String[] args) {
		int writeLine = 0;
		System.out.print("input how many line you'll write to file:");
		BufferedWriter bufferedWriter = null;
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		
		try {
			writeLine = Integer.parseInt(bufferedReader.readLine());
			bufferedWriter = new BufferedWriter(new FileWriter("test.txt"));
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		System.out.println("you will write " + writeLine + " to file");
		try {
			for (int i = 0; i < writeLine; ++i) {
				System.out.print("now writing " + (i + 1) + " line,input:");
				String temp = bufferedReader.readLine();
				bufferedWriter.write(temp);
				bufferedWriter.newLine();
			}
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} finally {
			try {
				bufferedReader.close();
				bufferedWriter.close();
			} catch (IOException e) {
				System.out.println(e.getMessage());
			}
		}
	}
}
