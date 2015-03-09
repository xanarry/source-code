import java.util.*;

enum Color {
	RED, BLUE, WHITE, GREEN;
} 

public class √∂æŸ¿‡ {
	public static void main(String[] args) {
		Color[] color = Color.values();
		for (Color t : color) {
			System.out.println(t);
		}

		System.out.print("input a color:");
		Scanner in = new Scanner(System.in);
		String input = in.nextLine();
		Color s = Enum.valueOf(Color.class, input);
		System.out.println(s);
	}
}

