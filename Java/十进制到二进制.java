import java.util.*;

public class ʮ���Ƶ������� {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input a decimal number:");
		int src = in.nextInt();
		String dest = traslate(src);
		System.out.println(dest);
	}

	static String traslate(int n) {
	/*  ������һ��
		String temp = "";
		
		while (n > 0) {
			/////////������ת��Ϊ�ַ����ķ���
			temp += Integer.toString(n%2);//��������ƣ�ϸ�ڲ���
			n /= 2;
		}

		int t = 0;
		char[] str = new char[temp.length()];
		//�������������ֵ�˳���ɷ���Ϊ��
		for (int i = temp.length() - 1; i >= 0; i--) {
			str[t++] = temp.charAt(i);
		}

		String result = new String(str);
	*/
		//�����ķ���
		String result = "";
		while (n > 0) {
			result  = Integer.toString(n%2) + result;
			n /= 2;
		}

		return result;
	}
} 