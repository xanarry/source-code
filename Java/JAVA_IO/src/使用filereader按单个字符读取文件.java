import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;


public class ʹ��filereader�������ַ���ȡ�ļ� {
//���ַ���ʽ��ȡ���������ĵ��ַ�����������ȡ
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input file name:");
		String filename = in.nextLine();
		
		FileReader fileReader = null;
		try {
			fileReader = new FileReader(filename);
			int t = 0;
			while ((t = fileReader.read()) != -1) {
				System.out.print((char)t);
			}
		} catch (IOException e1) {
			System.out.println("file not exist");
		} finally {
			try {
				fileReader.close();
			} catch (IOException e) {
				System.out.println(e.getMessage());
			}
		}
	}

}
