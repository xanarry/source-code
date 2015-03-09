import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Scanner;

public class ���ֽڸ����ļ� {
/*
 * �������Ʒ��ı��ļ�������Ƶ�����ֵȣ����õĻ�����Խ�󣬸��Ƶ��ٶ�Խ��
 * ����500MB���ļ�ʱ����512�Ļ�������С����32s536ms��ʹ��2014��С�Ļ���
 * ��ʱ�õ�25s572ms��ʱ��
 */
	public static void main(String[] args) {
		Scanner in  = new Scanner(System.in);
		System.out.print("input source file:");
		String src = in.nextLine();
		System.out.print("input destination file:");
		String dest = in.nextLine();
		
		InputStream inputStream = null;
		OutputStream outputStream = null;
		
		try {
			inputStream = new  FileInputStream(src);
			outputStream = new FileOutputStream(dest);
			byte[] buffer = new byte[1024];
			int len;
			long start = System.currentTimeMillis();
			System.out.println("copying...");
			while ((len = inputStream.read(buffer)) != -1) {
				outputStream.write(buffer, 0, len);
			}
			long end = System.currentTimeMillis();
			long diff = end - start;
			System.out.println("copyed seccessful time consume " + diff/1000 + "s" + diff%1000 + "ms");
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} finally {
			try {
				inputStream.close();
				outputStream.close();
			} catch (IOException e) {
				System.out.println(e.getMessage());
			}
		}
	}
}
