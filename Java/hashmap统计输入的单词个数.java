import java.util.HashMap;
import java.util.Iterator;
import java.util.Map.Entry;
import java.util.Scanner;

public class hashmapͳ������ĵ��ʸ��� {

	public static void main(String[] args) {
		HashMap<String, Integer> words = new HashMap<>();
		Scanner in = new Scanner(System.in);
		String word;
		while (!((word = in.nextLine()).equals(""))) {//�������Ϊ�յ�ʱ����ֹ����
			int count = 1;//Ĭ��һ�����ʾ��ǳ���һ��
			if (words.containsKey(word)) {//�жϸ�����ĵ����Ƿ��Ѿ�����
				count = words.get(word) + 1;//����Ѿ����ڣ��µĸ����������еĸ����ϼ�1
			}
			words.put(word, count);//�����µ�����
		}
		in.close();

		System.out.println("total have " + words.size() + " unique words");
		//����hashmap��������ʽ��listҪ�鷳һ�㣬˭�������ܸ��ḻ
		Iterator<Entry<String, Integer>> iterator = words.entrySet().iterator();
		while (iterator.hasNext()) {
			Entry<String, Integer> entry = (Entry<String, Integer>) iterator.next();
			System.out.println("you input \"" + entry.getKey() + "\" " + entry.getValue() + " times");
		}
	}
}
/*
hello
world
hello
c++
hello
java
*/