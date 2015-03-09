import java.util.*;

abstract class parent {//only if here define a abstract class then you can declare a abstract method in it
	public void display() {
		System.out.println("hello world");
	}

	public abstract int summination();//a abstract method
}

//Note: we can also substitute class parent as interface parent when implement a anonymous class

public class 匿名内部类抽象类 {
	public static void main(String[] args) {

		parent p = new parent() {//a anonymous inner class here 
			int s = 0;
			public int summination() {//implement its method 
				for (int i = 0; i <= 100; i++) {
					s += i;
				}
				return s;
			}
		};

		p.display();
		System.out.println(p.summination());
	}
}