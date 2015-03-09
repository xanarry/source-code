public class 简单异常 {
	public static void main(String[] args) {
		int[] a = new int[3];
		try {
			a[3] = 100;
		} catch (ArrayIndexOutOfBoundsException e) {
			a[2] = 100;
			System.out.println(e);
			System.out.println("下标越界");
		}
		System.out.println(a[a.length - 1]);
	}
}