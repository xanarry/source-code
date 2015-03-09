import java.util.*;

public class arraylist {
	public static void main(String[] args) {
		ArrayList<Integer> List = new ArrayList<Integer>();
		for (int i = 0; i < 100; i++) {
			List.add(i * i);
		}

		for (int i = 0; i < 100; i++) {
			System.out.println(List.get(i));
		}
	}
}