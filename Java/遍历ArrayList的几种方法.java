import java.util.*;

public class 遍历ArrayList的几种方法 {
	public static void main(String[] args) {
		ArrayList<String> str = new ArrayList<String>();//construct a ArrayList str
		for (int i = 0; i < 50; i++) {
			str.add(String.valueOf(i * i));//asignment value to each elements;
		}

		Collections.sort(str);//sort this arraylist by dictionary sequence

		System.out.println("first method to traverse ArrayList");
		for (int i = 0; i < str.size(); i++) {//just using loop to traverse the arraylist
			System.out.print(str.get(i) + " ");
		}

		System.out.println("\n\nsecond method to traverse ArrayList");
		Iterator<String> iter = str.iterator();//using iterator to traverse
		while (iter.hasNext()) {
			System.out.print(iter.next() + " ");
		}

		System.out.println("\n\nthird method to traverse ArrayList");
		for (String t : str) {
			System.out.print(t + " ");
		}

		System.out.println("\n\nforth method ot traverse ArrayList");
		for (Iterator<String> iter1 = str.iterator(); iter1.hasNext();) {
			System.out.print(iter1.next() + " "); 
		}
		System.out.println();
	}
}