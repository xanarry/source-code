import java.util.*;

public class Լɪ�� {
	public static void main(String[] args) {
		System.out.print("input number of people:");
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		System.out.print("input quit number:");
		int quit = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = 1;
		}

		int index = 0;
		int count = 1;//���ڱ���
		int p = n;//����ʣ������

		while (p > 1) {//ʣ����������1����������
			if (a[index] == 1) {//�����ǰλ������
				count++;
				if (count == quit) {
					a[index] = 0;//����m����
					count = 1;//����m����
					p--;//������1
				}
			}
			if (++index == n)//ѭ������
				index = 0;
		}

		for (int i = 0; i < n; i++) {
			if (a[i] != 0)
				System.out.println("the last one still remain is " + i);
		}
	}
}
