public class Echo {
	public static void main(String[] args) {
		System.out.println("you input " + args.length + " arguments");
		for (String t : args) {
			System.out.println(t);
		}
	}
}