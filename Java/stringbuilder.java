import static java.lang.StringBuilder.*;
public class stringbuilder {
	public static void main(String[] args) {
		StringBuilder builder = new StringBuilder();
		builder.append("hello");
		builder.append(' ');
		builder.append("world ");
		String s1 = builder.toString();
		System.out.println(s1);
		int i;
		for (i = 0; i < 5; i++) {
			builder.append(i + "-");
		}
		String s2 = builder.toString();
		System.out.println(s2 + "and its lengh is " + s2.length());
	}
}