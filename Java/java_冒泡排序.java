import java.util.*;

public class java_√∞≈›≈≈–Ú {
	public static void main(String[] args) {
		System.out.print("input the count of the numbers you wanna sort:");
		Scanner in = new Scanner(System.in);
		int count = in.nextInt();
		int[] numbers = new int[count];

		for (int i = 0; i < count; i++) {
			numbers[i] = (int)(Math.random() * 20);
		}

		System.out.println("original array:");
		for (int t : numbers) {
			System.out.print(t + " ");
		}
		/*
		for (int i = 0; i < numbers.length - 1; i++) {
			for (int j = 0; j < numbers.length - 1 - i; j++) {
				if (numbers[j] > numbers[j + 1]) {
					int temp = numbers[j];
					numbers[j] = numbers[j + 1];
					numbers[j + 1] = temp;
				}
			}
		}
		*/
		
		java_√∞≈›≈≈–Ú t = new java_√∞≈›≈≈–Ú();
		t.sort(numbers);

		System.out.println("\nafter sorted");
		for (int t1 : numbers) {
			System.out.print(t1 + " ");
		}
		System.out.println();
	}

	void sort(int a[]) {
		for (int i = 0; i < a.length - 1; i++) {
			for (int j = 0; j < a.length - 1 - i; j++) {
				if (a[j] < a[j + 1]) {
					int temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
	}
}