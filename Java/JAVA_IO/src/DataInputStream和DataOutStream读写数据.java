import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;


public class DataInputStreamºÍDataOutStream¶ÁÐ´Êý¾Ý {

	public static void main(String[] args) {
		final int lenX = 10; 
		final int lenY = 10;
		DataOutputStream dataOutputStream = null;
		FileOutputStream outputStream = null;
		DataInputStream dataInputStream = null;
		FileInputStream inputStream = null;
		
		try {
			outputStream = new FileOutputStream("1111.txt");
			dataOutputStream = new DataOutputStream(outputStream);
			dataOutputStream.writeInt(lenX);
			dataOutputStream.writeInt(lenY);
			
			for (int i = 0; i < lenX; i++) {
				for (int j = 0; j < lenY; j++) {
					dataOutputStream.writeInt((int) (Math.random() * 90 + 10));
				}
			}
			
			int a = 0; 
			int b = 0;
			inputStream = new FileInputStream("1111.txt");
			dataInputStream = new DataInputStream(inputStream);
			a = dataInputStream.readInt();
			b = dataInputStream.readInt();
			
			int[][] temp = new int[a][b];
			
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					temp[i][j] = dataInputStream.readInt();
				}
			}
			
			System.out.println("lenX = " + a + " lenY = " + b);
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					System.out.print(temp[i][j] + " ");
				}
				System.out.println();
			}
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} finally {
			try {
				dataOutputStream.close();
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
		}

	}

}
