import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class 读取二维数组 {
	@SuppressWarnings("resource")
	public static void main(String[] args) {
		BufferedReader reader = null;
		Scanner in = null;
		try {
			reader = new BufferedReader(new FileReader("test.txt"));
			String len = reader.readLine();
			in = new Scanner(len).useDelimiter(" ");
			int lenX = in.nextInt();
			int lenY = in.nextInt();
			
			int[][] array = new int[lenX][lenY];
			for (int i = 0; i < lenX; i++) {
				String getElement = reader.readLine();
				in = new Scanner(getElement).useDelimiter(" ");
				for (int j = 0; j < lenY; j++) {
					array[i][j] = in.nextInt();
				}
			}
			
			System.out.println(lenX + " " + lenY);
			for (int i = 0; i < lenX; i++) {
				for (int j = 0; j < lenY; j++) {
					System.out.print(array[i][j] + " ");
				}
				System.out.println();
			}
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} catch (Exception e) {
			System.out.println(e.getMessage());
		} finally {
			try {
				reader.close();
				in.close();
			} catch (Exception e) {
				e.getStackTrace();
			}
		}
	}
}
