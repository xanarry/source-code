import java.util.*;
import java.io.*;

public class ѧ���ɼ�д���ļ� {
	public static void main(String[] args) {
		final int STU_COUNT = 5;
		final int CONTENT = 6;
		Scanner in = new Scanner(System.in);
		String[][] stu = new String[STU_COUNT][CONTENT];
		int sum = 0;
		for (int i = 0; i < STU_COUNT; i++) {
			System.out.print("input student " + (i + 1) + " name: ");
			stu[i][0] = in.nextLine();
			System.out.print("input student " + (i + 1) + " stu_no: ");
			stu[i][1] = in.nextLine();
			
			sum = 0;

			for (int j = 0; j < 3; j++) {
				System.out.print("input score " + j + " : ");
				stu[i][2 + j] = in.nextLine();
				sum += Integer.parseInt(stu[i][2 + j]);
			}
			stu[i][CONTENT - 1] = String.valueOf(sum/3);
		}

		try {
			File f = new File("student_info.txt");//�����ļ�����
			if (f.exists()) {
				System.out.println("file has exist");
			} 
			else {
				System.out.println("file creating");
				f.createNewFile();//����ʵ���ļ�
			}
			BufferedWriter output = new BufferedWriter(new FileWriter(f));//����������
			for (int i = 0; i < STU_COUNT; i++) {
				output.write((i + 1) + " : ");//д���ļ�
				for (int j = 0; j < CONTENT; j++) {
					output.write(stu[i][j] + " ");
			//		System.out.print(stu[i][j] + " ");
				}
				output.write("\n");
			//	System.out.println();
			} 
			output.close();
			System.out.println("data has writed to file");
		}
		catch (Exception e) {
			e.printStackTrace();
		}
 	}
}