import java.util.*;
public class Êı×Ö¼ÓÃÜ {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input a new number in range(1000-9999):");
		int input = in.nextInt();
		int digit1 = input / 1000;
		int digit2 = (input - digit1 * 1000) / 100;
		int digit3 = (input - digit1 * 1000 - digit2 * 100) / 10;
		int digit4 = input % 10;

		digit1 = (digit1 + 9) % 10;
		digit2 = (digit2 + 9) % 10;
		digit3 = (digit3 + 9) % 10;
		digit4 = (digit4 + 9) % 10;

		int temp = digit1;
		digit1 = digit3;
		digit3 = temp;

		temp = digit2;
		digit2 = digit4;
		digit4 = temp;

		System.out.println(digit1 + "" + digit2 + "" + digit3 + "" + digit4);
	}
}