/*
 *本程序中的运算表达式不能包含括号，运算优先级无论加减乘除，均从左向右计算
 */
import java.util.*;
import java.lang.*;

public class 表达式计算 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input a expresion:");
		String str = in.nextLine();//输入表达式

		int result = 0;//初始化结果
		int i;//下标
		//获取数的方式为(假如是124+23=,即1*100 + 2*10 + 4)
		for (i = 0; Character.isDigit(str.charAt(i)); i++) {
			result = result*10 + (int)(str.charAt(i) - 48);//获取表达是的第一个数
		}
		char opertor = str.charAt(i);//获取表示的第一个运算符

		int getnum = 0;//设置变量获取下个数的值
		for (int j = i + 1; j < str.length(); j++) {
			if (Character.isDigit(str.charAt(j))) {
				getnum = getnum*10 + (int)(str.charAt(j) - 48);//获取下一个数
			}
			else {
				switch (opertor) {//执行运算
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
				opertor = str.charAt(j);//获取新的运算符
				getnum = 0;//重置临时变量储存新的数值
			}
		}
		System.out.println(str + result);//输出表达式和结果
	}
}