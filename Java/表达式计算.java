/*
 *�������е�������ʽ���ܰ������ţ��������ȼ����ۼӼ��˳������������Ҽ���
 */
import java.util.*;
import java.lang.*;

public class ���ʽ���� {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input a expresion:");
		String str = in.nextLine();//������ʽ

		int result = 0;//��ʼ�����
		int i;//�±�
		//��ȡ���ķ�ʽΪ(������124+23=,��1*100 + 2*10 + 4)
		for (i = 0; Character.isDigit(str.charAt(i)); i++) {
			result = result*10 + (int)(str.charAt(i) - 48);//��ȡ����ǵĵ�һ����
		}
		char opertor = str.charAt(i);//��ȡ��ʾ�ĵ�һ�������

		int getnum = 0;//���ñ�����ȡ�¸�����ֵ
		for (int j = i + 1; j < str.length(); j++) {
			if (Character.isDigit(str.charAt(j))) {
				getnum = getnum*10 + (int)(str.charAt(j) - 48);//��ȡ��һ����
			}
			else {
				switch (opertor) {//ִ������
					case '+':
						result += getnum;
						break;
					case '-':
						result -= getnum;
						break;
					case '*':
						result *= getnum;
						break;
					case '/':
						result /= getnum;
						break;
				}	
				opertor = str.charAt(j);//��ȡ�µ������
				getnum = 0;//������ʱ���������µ���ֵ
			}
		}
		System.out.println(str + result);//������ʽ�ͽ��
	}
}