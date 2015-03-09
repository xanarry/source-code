import java.util.*;

public class hashSet {
	public static void main(String[] args) {
		HashSet<String> words =  new HashSet<String>();
		Scanner in = new Scanner(System.in);
		String input;
		int count = 0;
		while (! (input = in.nextLine()).equals("")) {
			count++;
			words.add(input);
		}

		System.out.println("input " + count + " times");
		System.out.println("have " + words.size() + " unique words");
		Iterator iter = words.iterator();
		while (iter.hasNext()) {
			System.out.println(iter.next());
		}
	}
}