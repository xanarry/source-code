import java.util.*;

public class �Ӽ������ʽ {
	public static void main(String[] args) {
		System.out.println("input a expresion:");
		Scanner in = new Scanner(System.in);
		int fac1 = in.nextInt();
		char operator = (in.next()).charAt(0);//���������ɿո��������������ı��ʽ���������Ҫ�ÿո����
		while (operator != '=') {
			int fac2 = in.nextInt();
			switch (operator) {
				case '+':
					fac1 += fac2;
					break;
				case '-':
					fac1 -= fac2;
					break;
			}
			operator = (in.next()).charAt(0);
		}
		System.out.print(fac1);
	}
}