public class  ‰≥ˆFibonacci–Ú¡– {
	public static void main(String[] args) {
	//	1 1 2 3 5 8 13 21
		long[] fibonacci = new long[50];
		fibonacci[0] = fibonacci[1] = 1;

		System.out.println(fibonacci[0]);
		System.out.println(fibonacci[1]);

		for (int i = 2; i < 100; i++) {
			fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
			System.out.println(fibonacci[i]);
		}
	}
}