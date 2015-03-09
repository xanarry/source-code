import java.io.IOException;
import java.nio.file.DirectoryStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class ±éÀúÎÄ¼þ¼Ð {

	public static void main(String[] args) {
		Path dirPath;
		dirPath = Paths.get("E:\\");
		DirectoryStream<Path> directory = null;
		try {
			directory = Files.newDirectoryStream(dirPath);
			for (Path p : directory) {
				System.out.println(p.getFileName());
			}
		} catch (IOException e) {
			System.out.println(e.getMessage());
		}
	}
}
