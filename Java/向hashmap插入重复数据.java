import java.util.HashMap;
import java.util.Iterator;
import java.util.Map.Entry;

public class 向hashmap插入重复数据 {

	public static void main(String[] args) {
		HashMap<String, Integer> hashMap = new HashMap<>();
		hashMap.put("A", 100);
		hashMap.put("A", 200);
		hashMap.put("B", 300);
		hashMap.put("B", 300);
		hashMap.put("C", 400);
		hashMap.put("D", 500);
	
		System.out.println(hashMap.size());
		Iterator<Entry<String, Integer>> iterator = hashMap.entrySet().iterator();
		while (iterator.hasNext()) {
			Entry<String, Integer> entry = (Entry<String, Integer>) iterator.next();
			System.out.println(entry.getKey() + ": " + entry.getValue());
			
		}

	}

}
