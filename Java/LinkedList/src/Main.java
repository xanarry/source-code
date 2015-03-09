
public class Main {
	public static void main(String[] args) {
		System.out.println("single linked list");
		System.out.println("=====================================");
		SingleLinkedList singleLinkedList = new SingleLinkedList();
		
		for (int i = 0; i < 10; i++) {//尾部插入法
			singleLinkedList.insertBack(i);
		}
		
		singleLinkedList.traverse();
		
		SingleLinkedList singleListb = new SingleLinkedList();
		
		for (int i = 0; i < 10; i++) {//头部插入法
			singleListb.insertFront(i);
		}
		
		singleListb.traverse();
		
		System.out.println("\ndoube linked list");
		System.out.println("=====================================");
		DoubleLinkedList doubleLinkedList = new DoubleLinkedList();
		
		for (int i = 0; i < 10; i++) {//头部插入法
			doubleLinkedList.insertFront(i);
		}
		
		doubleLinkedList.traverseFromHead();//头部开始遍历
	//	doubleList.traverseFromTail();//尾部开始遍历
		
		doubleLinkedList.deleteFirstElement(5);
		doubleLinkedList.deleteLastElement(8);
		doubleLinkedList.traverseFromHead();
		
		System.out.println(doubleLinkedList.length());
	}
}
