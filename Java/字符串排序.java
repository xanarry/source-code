import java.util.*;

public class �ַ������� {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("input 5 string");
		String[] str = new String[5];
		for (int i = 0; i < 5; i++) {
			str[i] = in.nextLine();
		}

		String temp;
		for (int i = 0; i < 5 - 1; i++) {//ð������
			for (int j = 0; j < 5 - i - 1; j++) {
				if (strcmp(str[j], str[j + 1])) {//�ȽϺ���
					temp = str[j];
					str[j] = str[j + 1];
					str[j + 1] = temp;
				}
			}
		}

		for (String t : str) {
			System.out.println(t);
		}
	}

	static boolean strcmp(String a, String b) 
	{
		for (int i = 0; i < a.length() && i < b.length(); i++) 
		{
			if (a.charAt(i) > b.charAt(i)) 
				return true;
			else if (a.charAt(i) < b.charAt(i)) 
				return false;
			else {
				if (a.length() >= b.length())
					return true;
				else 
					return false;
				}
		}
		return true;//������ڴ���������ȫ��ͬ���ַ���
	}
}