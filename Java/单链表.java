import java.util.*;

class Node {
	private String name;
	private int score;
	public Node next;

	public Node(String n, int s) {
		name = n;
		score = s;
	}

	public String toString() {
		return name + " : " + score;
	}
}

public class µ¥Á´±í {
	public static void main(String[] args) {
		Node head = new Node("START", -1);
		head.next = null;
		Node pre = null;

		for (int i = 0; i < 100; i++) {
			Node newNode = new Node(String.valueOf(i + 1), (int)(Math.random()*50) + 50);
			newNode.next = null;

			if (head.next == null) 
				head.next = newNode;
			else 
				pre.next = newNode;
		
			pre = newNode;
		}

		Node temp = head.next;

		while (temp != null) {
			System.out.println(temp);
			temp = temp.next;
		}
	}
}