import java.util.*;
public class �����¶�ת���������¶� {
	public static void main(String[] args) {
		System.out.print("input a temperature:");
		Scanner in = new Scanner(System.in);
		double i = in.nextDouble();
		double o = 5*(i-50)/9+10;
		System.out.println("after conversion:" + o);
	}
}