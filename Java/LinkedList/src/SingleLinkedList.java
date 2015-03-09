public class SingleLinkedList {
	class Node {
		int data;
		Node next;
	}

	private Node head;
	private int length;

	public SingleLinkedList() {
		head = new Node();
		length = 0;
	}

	public void insertBack(int n) {
		Node newNode = new Node();
		newNode.data = n;
		newNode.next = null;

		if (head.next == null) {
			head.next = newNode;
		} else {
			Node currentNode = head.next;
			while (currentNode.next != null) {
				currentNode = currentNode.next;
			}
			newNode.next = currentNode.next;
			currentNode.next = newNode;
		}
		length++;
	}

	public void insertFront(int n) {
		Node newNode = new Node();
		newNode.data = n;
		newNode.next = null;

		newNode.next = head.next;
		head.next = newNode;
		
		length++;
	}

	public void traverse() {
		if (head.next == null) {
			System.out.println("LinkedList is null");
			return;
		}

		Node currentNode = head.next;
		while (currentNode != null) {
			System.out.print(currentNode.data + " ");
			currentNode = currentNode.next;
		}
		System.out.println();
	}

	public int delete(int n) {//delete according to index
		int eleValue = 0;
		Node currentNode = head;
		Node pre = head;
		int count = 0;
		while (currentNode != null && count != n) {
			pre = currentNode;
			currentNode = currentNode.next;
			count++;
		}
		pre.next = currentNode.next;
		length--;
		return eleValue;
	}

	public int deleteElement(int n) {//delete according to element value
		int count = 0;
		Node currentNode = head;
		Node pre = head;
		while (currentNode != null && currentNode.data != n) {
			pre = currentNode;
			currentNode = currentNode.next;
			count++;
		}
		pre.next = currentNode.next;
		length--;
		return count;
	}

	public int length() {
		return length;
	}
}
