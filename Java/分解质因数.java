import java.util.*;

public class �ֽ������� {
	public static void main(String[] args) {
		System.out.print("input a number:");
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		System.out.print(n + " = ");

		int i = 2;//����С����2��ʼ����
		while (n != i) {//���������ͳ�������ȵ�ʱ��ͼ�������
			if (n%i == 0) {//���������ܱ�i����
				System.out.print(i + "*");//��������
				n /= i;//��nȡ��
			}
			else//���粻�ܱ���ǰ�������������Ӧ���ó�����1
				i++;
		}
		System.out.print(i);
		System.out.println();
	}
}