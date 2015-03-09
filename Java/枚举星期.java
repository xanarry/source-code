public class Ã¶¾ÙÐÇÆÚ {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Day Of Week");
		for (dayOfweek day : dayOfweek.values()) {
			System.out.printf("%s ", day);
		}
		System.out.println();
	}

}

enum dayOfweek {
	MONDAY, TUESDAY, WENDESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY;
	
	public String toString() {
		String s = super.toString();
		return s.substring(0, 1) + s.substring(1).toLowerCase();
	}
}
