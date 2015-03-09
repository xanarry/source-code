import java.io.FileReader;
import java.io.StreamTokenizer;

public class StreamTokenizerͳ�Ƶ��ʸ��� {

	public static void main(String[] args) {
		final String fileName = "1111.txt";
		FileReader reader = null;
		StreamTokenizer streamTokenizer = null;
		
		try {
			int wordCount = 0;
			int numberCount = 0;
			int others = 0;
			
			reader = new FileReader(fileName);
			//������һ��FILEREADER����FILEINPUTSTREAM�������FILEREADER
			streamTokenizer = new StreamTokenizer(reader);
			streamTokenizer.slashSlashComments(true);//���Ե���ע�͵�����
			streamTokenizer.slashStarComments(true);//���Զ���ע���ܵ�����
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
