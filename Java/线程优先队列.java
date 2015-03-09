import java.util.ArrayList;
import java.util.PriorityQueue;

public class 线程优先队列 {

	public static void main(String[] args) {
		ArrayList<Integer> list = new ArrayList<>();
		for (int i = 0; i < 100; i++) {
			list.add((int) (Math.random() * 10));
		}
		
		PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();
		priorityQueue.addAll(list);
		
		System.out.println("waiting thread......");
		for (Integer t : priorityQueue) {
			System.out.print(t + ",");
		}
		
		System.out.println("\ndeploying thread......");
		while (!priorityQueue.isEmpty()) {
			System.out.print(priorityQueue.remove() + ",");
		}

	}

}
