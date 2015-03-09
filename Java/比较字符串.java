public class ±È½Ï×Ö·û´® {
	public static void main(String[] args) {
		String greet = "hello";
		if (greet.equals("hello")) {
			System.out.println(greet + " equal to " + "hello");
		}

		if (greet.substring(0, 3).equals("hel")) {
			System.out.println(greet.substring(0, 3) +" equal to \"hel\"");
		}

		if (greet.substring(3).equalsIgnoreCase("LO")) {
			System.out.println(greet.substring(3) + "equal to \"LO\"");
		}

		String tmp = "world";
		if (tmp.equals(greet))
			System.out.println(tmp + "==" + greet);
		else
			System.out.println(tmp + "!=" + greet);
		
		String fullgreeting = greet + " " + tmp;
		System.out.println(fullgreeting);
	}
}