import java.util.*;

public class tobinary {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input a integer:");
		int input = in.nextInt();
		System.out.println(input + " convert to binary is: " + Integer.toString(input, 2));//convert decade number to string in binary format
	}
}