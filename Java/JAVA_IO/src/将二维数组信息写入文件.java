import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class ����ά������Ϣд���ļ� {

	public static void main(String[] args) {
		final int LenX = 10;
		final int LenY = 10;
		
		Writer writer = null;
		try {
			writer = new FileWriter("test.txt");
			writer.write(String.valueOf(LenX) + " " + String.valueOf(LenY) + "\n");
			for (int i = 0; i < LenX; i++) {
				for (int j = 0; j < LenY; j++) {
					int temp = (int) (Math.random() * 90 + 10);
					writer.write(String.valueOf(temp));//ֻ��ת����д�����ݲ������֣���Ȼ���ļ���ʾ������Ӧֵ��Ӧ��ASC���ֵ
					writer.write(" ");
				}
				writer.write("\n");
			}
		} catch (IOException e) {
			e.getStackTrace();
		} finally {
			try {
				writer.close();
			} catch (Exception e2) {
				e2.getStackTrace();
			}
		}
	}
}
