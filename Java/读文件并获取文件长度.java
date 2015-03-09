import java.io.*;

public class 读文件并获取文件长度 {
	public static void main(String[] args) {
		int count = 0; 

		InputStream streamReader = null;//inputStream是FileInputStream的父类
		if (args.length < 1) {//没有输入文件名直接退出
			System.out.println("Usage: java Filelength <filename>");
			System.exit(0);
		}

		try {
			streamReader = new FileInputStream(args[0]);//创建文件输入流对象
			while (streamReader.read() != -1) {//调用read方法读取文件内容
				count++;//累加文件字节数量
			}
			System.out.println(new File(args[0]).length());
			System.out.println(args[0] + "Filelength = " + count);//输出文件字节长度
			streamReader.close();
		} catch (FileNotFoundException fe) {
			System.out.println(fe.getMessage());
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} finally {
			try {
				streamReader.close();
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
		}
	}
}