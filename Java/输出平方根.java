import java.util.*;
public class 输出平方根 {
	public static void main(String[] args) {
		System.out.print("input a number:");
		Scanner in = new Scanner(System.in);
		double number = in.nextDouble();
		System.out.println("sqrt(" + number + ") = " + Math.sqrt(number));
	}
}