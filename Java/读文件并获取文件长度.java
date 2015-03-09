import java.io.*;

public class ���ļ�����ȡ�ļ����� {
	public static void main(String[] args) {
		int count = 0; 

		InputStream streamReader = null;//inputStream��FileInputStream�ĸ���
		if (args.length < 1) {//û�������ļ���ֱ���˳�
			System.out.println("Usage: java Filelength <filename>");
			System.exit(0);
		}

		try {
			streamReader = new FileInputStream(args[0]);//�����ļ�����������
			while (streamReader.read() != -1) {//����read������ȡ�ļ�����
				count++;//�ۼ��ļ��ֽ�����
			}
			System.out.println(new File(args[0]).length());
			System.out.println(args[0] + "Filelength = " + count);//����ļ��ֽڳ���
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