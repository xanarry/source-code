import java.util.*;

public class 加减法表达式 {
	public static void main(String[] args) {
		System.out.println("input a expresion:");
		Scanner in = new Scanner(System.in);
		int fac1 = in.nextInt();
		char operator = (in.next()).charAt(0);//由于输入由空格隔开，所以输入的表达式数字与符号要用空格隔开
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