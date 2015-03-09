import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Scanner;

public class 按字节复制文件 {
/*
 * 用来复制非文本文件，如视频，音乐等，设置的缓冲区越大，复制的速度越快
 * 复制500MB的文件时设置512的缓冲区大小用了32s536ms，使用2014大小的缓冲
 * 区时用的25s572ms的时间
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
