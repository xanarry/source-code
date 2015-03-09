import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class 将二维数组信息写入文件 {

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
					writer.write(String.valueOf(temp));//只有转换后写的内容才是数字，不然打开文件显示的是相应值对应的ASC码的值
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
