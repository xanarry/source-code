import java.util.*;

class ReadyForOdds {//generate 50 odds;
	private final int SIZE = 50;
	private int[] randomNum = new int[SIZE];

	public ReadyForOdds() {
		for (int i = 0; i < SIZE; i++) {
			randomNum[i] = (int)(Math.random() * 100) + 1;//initialize each element of the array
		}
	}

	public void output() {//output each odds in this array
		myIterator inter = new myIterator();//inner class to imitate iterator
		while (inter.hasNext()) {
			int temp = inter.next();
			if (temp != -1)//if it is not a odds will return -1;
				System.out.println(temp);
		}
	}

	private class myIterator {//define the inner class 
		private int next = 0;//record the index of the array

		public boolean hasNext() {
			return next < SIZE;//index is smaller than Size
		}

		public int next() {
			int temp = randomNum[next++];
			if (temp % 2 != 0)
				return temp;
			else
				return -1;
		}
	}
}

public class 内部类输出奇数 {
	public static void main(String[] args) {
		ReadyForOdds numbers = new ReadyForOdds();
		numbers.output();
	}
}