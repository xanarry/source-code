import java.io.File;


public class �鿴�ļ�·�� {
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
