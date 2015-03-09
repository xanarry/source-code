public class 求最大值及其下标 {
	public static void main(String[] args) {
		int[] a = new int[20];
		for (int i = 0; i < 20; i++) {
			a[i] = (int)(Math.random() * 100);
			System.out.print(a[i] + " ");
		}
		
		int index = 0; 
		for (int i = 0; i < 20; i++) {
			if (a[index] < a[i]) {
				index = i;
			}
		}
		System.out.println("\nmax = " + a[index]);
		System.out.println("index = " + (index + 1));
	}
}