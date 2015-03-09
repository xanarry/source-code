public class selectsort {
	public static void main(String[] args) {
		System.out.println("oringinal array:");
		int[] a = new int[10];
		for (int i = 0; i < a.length; i++) {
			a[i] = (int)(Math.random() * 20);
			System.out.print(a[i] + " ");
		}
		System.out.println();

		selectsort sort = new selectsort();
		sort.sort(a);

		System.out.println("after selectsort:");
		for (int t : a) {
			System.out.print(t + " ");
		}
		System.out.println();
	}

	void sort(int a[]) {
		for (int i = 0; i < a.length; i++) {
			int k = i; 
			for (int j = i + 1; j < a.length; j++) {
				if (a[j] > a[k])
					k = j;
			}
			if (k != i)
			{
				int temp = a[k];
				a[k] = a[i];
				a[i] = temp;
			}
		}
	}
}
