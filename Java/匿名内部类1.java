import java.util.*;

interface Count {
	public int count();
}

class Test1 {
	public int count(int base) {//to make a conflect to inherit class
		int sum = 0;
		for (int i = 1; i <= base; i++) {
			sum += i;
		}
		return sum;
	}
}

//here we use Anonymous Inner Class to avoid the conflect of method 'count' of parent and child
class Test2 extends Test1 {

	public Count mycount(int n) {
		return new Count() {
			int sum = 0; 

			public int count() {
				for (int i = 1; i <= n; i++) {
					sum += i;
				}
				return sum;
			}
		};//the whole section from line 21 above is a return sentence, do not forget add a semicolon

	}
}

public class 匿名内部类1 {
	public static void main(String[] args) {
		Test1 t1 = new Test1();
		System.out.println(t1.count(100));//test parent class 

		Test2 t2 = new Test2();//test anonymous inner class
		Count c = t2.mycount(1000);//return type is a interface
		System.out.println(c.count());
	}
}