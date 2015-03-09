import java.io.FileReader;
import java.io.StreamTokenizer;

public class StreamTokenizer统计单词个数 {

	public static void main(String[] args) {
		final String fileName = "1111.txt";
		FileReader reader = null;
		StreamTokenizer streamTokenizer = null;
		
		try {
			int wordCount = 0;
			int numberCount = 0;
			int others = 0;
			
			reader = new FileReader(fileName);
			//参数是一个FILEREADER或者FILEINPUTSTREAM，最好是FILEREADER
			streamTokenizer = new StreamTokenizer(reader);
			streamTokenizer.slashSlashComments(true);//忽略单行注释的内容
			streamTokenizer.slashStarComments(true);//忽略多行注释总的内容
			while (streamTokenizer.nextToken() != StreamTokenizer.TT_EOF) {
				if (streamTokenizer.ttype == StreamTokenizer.TT_NUMBER) {
					numberCount++;
				} else if (streamTokenizer.ttype == StreamTokenizer.TT_WORD) {
					wordCount++;
				} else {
					others++;
				}
			}
			
			System.out.println("word:" + wordCount);
			System.out.println("number:" + numberCount);
			System.out.println("others:" + others);
		} catch (Exception e) {
			System.out.println(e.getMessage());
		} finally {
			try {
				reader.close();
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
		}
	}
}
