import java.util.*;

public class �۰���� {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[] a = {1, 23, 34, 35, 42, 47, 49, 51, 55, 57, 60, 64, 69, 73, 77, 78, 80, 85, 89, 92, 96, 100};
		for (int t : a) {
			System.out.print(t + " ");
		}

		System.out.print("\ninput a number you wanna find:");
		int obj = in.nextInt();
		int l = 0;
		int r = a.length;
		int m = (l + r) / 2;
		int count = 0;
		while (a[m] != obj) {//���û���ҵ��ͼ�������
			count++;//ÿ����һ�����������Լ�
			if (count == a.length) {
				System.out.println("find nothing");//���������ÿ��Ԫ�ض�û���ҵ�
				break;
			}

			if (obj > a[m])//������е�������ұ߼����۰����
				l = m;

			if (obj < a[m])//����������۰����
				r = m;
			m = (l + r) / 2;
		}
		
		if (count < a.length)//����ҵ���
			System.out.println("the index of " + obj + " is " + (m + 1));
	}
}