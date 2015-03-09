import java.util.*;

public class ³É¼¨ÅÐ¶Ï {
	public static void main(String[] args) {
		System.out.println("input a score");
		Scanner in = new Scanner(System.in);
		int score = in.nextInt();
		if (score >= 90)
			System.out.println(score + "-> degree is A");
		else if (80 <= score)
			System.out.println(score + "-> degree is B");
		else if (70 <= score)
			System.out.println(score + "-> degree is C");
		else if (60 <= score)
			System.out.println(score + "-> degree is D");
		else
			System.out.println(score + "-> degree is E");
	}
}