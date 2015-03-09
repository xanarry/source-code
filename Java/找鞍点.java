import java.util.*;

public class �Ұ��� {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input n:");
		int n = in.nextInt();	

		int[][] a = new int[n][n];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = (int)(Math.random() * n * n);
				System.out.printf("%2d ", a[i][j]);
			}
			System.out.println();
		}
		
		int h_index = 0; 
		int v_index = 0;
		boolean flag = false;

		for (int i = 0; i < n; i++) {//���ϵ��£�����ÿ��
			h_index = 0;
			for (int j = 0; j < n; j++) {//����ÿ��
				if (a[i][h_index] < a[i][j]) {//�ҵ�ÿ�е�������
					h_index = j;//��ȡ������������±�
				}
			}
			v_index = i;//��¼��ǰ�е�λ��
			for (int k = 0; k < n; k++) {//������ǰ����������ڵ���
				if (a[v_index][h_index] > a[k][h_index]) {
					v_index = k;//�ҵ�����С���б��
				}
			}

			if (v_index == i) {//�����û�б䣬�����Ѿ�����С
				flag = true;//���ñ��
				break;
			}
		}

		if (flag)
			System.out.println("a[" + v_index + "]" + "[" + h_index + "] = " + a[v_index][h_index]);//������
		else
			System.out.println("NO THIS POINT��");
	}	
}