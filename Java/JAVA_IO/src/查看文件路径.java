import java.io.File;


public class 查看文件路径 {
	public static void main(String[] args) {
		File file = new File("test.txt");
		if (!file.exists()) {
			System.out.println("file is not exist");
			System.exit(0);
		}
		System.out.println("file existed");
		System.out.println(file.getAbsolutePath());
		
	}

}
