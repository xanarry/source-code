import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;

public class 内置的集合算法使用 {

	public static void main(String[] args) {
		ArrayList<Integer> list = new ArrayList<>();
		for (int i = 0; i < 50; i++) {
			list.add((int) (Math.random() * 100));
		}
		
		System.out.println("original list");
		System.out.println(list.toString());
		
		Collections.sort(list);
		System.out.println("\nafter sorted");
		System.out.println(list.toString());
		
		System.out.println("\nthe index of 10 in the sorted list");
		System.out.println(Collections.binarySearch(list, 10));
		
		System.out.println("\nmax num of this list");
		System.out.println(Collections.max(list));
		
		System.out.println("\nmin num of this list");
		System.out.println(Collections.min(list));
		
		System.out.println("\nfrequency of 2 in this list");
		System.out.println(Collections.frequency(list, 2));
		
		HashSet<Integer> hashSet = new HashSet<>();
		hashSet.addAll(list);
		System.out.println("\nnumber of distinct elements is ");
		System.out.println(hashSet.size());
		
		List<Integer> temp = new ArrayList<>();
		temp = list.subList(0, 10);
		System.out.println("\nsublist of sorted list's first 10 elements are ");
		System.out.println(temp);
	}

}
