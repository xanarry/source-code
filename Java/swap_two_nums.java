public class swap_two_nums {
	public static void main(String[] args) {
		int a = 3; 
		int b = 6;
		System.out.println("a = " + a + " b = " + b);
		swap(&a, &b);
		System.out.println("a = " + a + " b = " + b);
	}
	static void swap(int &a, int &b) {
		int t = a;
		a = b; 
		b = t;
	}
}

