
public class Main {
	public static void main(String[] args) {
		System.out.println("single linked list");
		System.out.println("=====================================");
		SingleLinkedList singleLinkedList = new SingleLinkedList();
		
		for (int i = 0; i < 10; i++) {//β�����뷨
			singleLinkedList.insertBack(i);
		}
		
		singleLinkedList.traverse();
		
		SingleLinkedList singleListb = new SingleLinkedList();
		
		for (int i = 0; i < 10; i++) {//ͷ�����뷨
			singleListb.insertFront(i);
		}
		
		singleListb.traverse();
		
		System.out.println("\ndoube linked list");
		System.out.println("=====================================");
		DoubleLinkedList doubleLinkedList = new DoubleLinkedList();
		
		for (int i = 0; i < 10; i++) {//ͷ�����뷨
			doubleLinkedList.insertFront(i);
		}
		
		doubleLinkedList.traverseFromHead();//ͷ����ʼ����
	//	doubleList.traverseFromTail();//β����ʼ����
		
		doubleLinkedList.deleteFirstElement(5);
		doubleLinkedList.deleteLastElement(8);
		doubleLinkedList.traverseFromHead();
		
		System.out.println(doubleLinkedList.length());
	}
}
