public class DoubleLinkedList {
	class Node {
		int data;
		Node pre;
		Node next;
	}

	private Node head;
	private Node tail;
	private int length;

	public DoubleLinkedList() {
		head = new Node();
		head.data = Integer.MIN_VALUE;
		head.pre = null;

		tail = new Node();
		tail.data = Integer.MAX_VALUE;
		tail.next = null;

		length = 0;

		head.next = tail;
		tail.pre = head;
	}

	public void insertFront(int n) {
		Node newNode = new Node();
		newNode.data = n;
		newNode.pre = null;
		newNode.next = null;

		newNode.next = head.next;
		head.next.pre = newNode;
		head.next = newNode;
		newNode.pre = head;
		
		length++;
	}

	public void insertBack(int n) {
		Node newNode = new Node();
		newNode.data = n;
		newNode.pre = null;
		newNode.next = null;

		newNode.pre = tail.pre;
		tail.pre.next = newNode;
		tail.pre = newNode;
		newNode.next = tail;
		
		length++;
	}

	public void traverseFromHead() {
		Node currentNode = head;
		currentNode = currentNode.next;
		while (currentNode != tail && currentNode != null) {
			System.out.print(currentNode.data + " ");
			currentNode = currentNode.next;
		}
		System.out.println();
	}

	public void traverseFromTail() {
		Node currentNode= tail;
		currentNode = currentNode.pre;
		while (currentNode != head && currentNode != null) {
			System.out.print(currentNode.data + " ");
			currentNode = currentNode.pre;
		}
		System.out.println();
	}

	public int deleteFirstElement(int n) {// delete according to element value first element
		int count = 0;
		Node currentNode = head;
		Node previousNode = head;

		while (currentNode != null && currentNode.data != n && currentNode != tail) {
			previousNode = currentNode;
			currentNode = currentNode.next;
			count++;
		}
		currentNode.next.pre = previousNode;
		previousNode.next = currentNode.next;
		
		length--;
		return count;
	}

	public int deleteLastElement(int n) {// delete according to element value last element
		int count = 0;
		Node currentNode = tail;
		Node previousNode = tail;

		while (currentNode != null && currentNode.data != n && currentNode != head) {
			previousNode = currentNode;
			currentNode = currentNode.pre;
			count++;
		}
		currentNode.pre.next = previousNode;
		previousNode.pre = currentNode.pre;
		
		length--;
		return count;
	}

	public int delete(int index) {// delete according to index
		int count = 0;
		Node currentNode = head;
		Node previousNode = head;

		while (currentNode != null && currentNode != tail && count < index) {
			count++;
			previousNode = currentNode;
			currentNode = currentNode.next;
		}
		previousNode.next = currentNode.next;
		
		length--;
		return previousNode.data;
	}

	public int length() {
		return length;
	}

}
