public class ����һ�δ���ִ�е�ʱ�� {
	public static void main(String[] args) throws InterruptedException {
		long start = System.currentTimeMillis();
		long sum = 0;
		for (int i = 0; i <= 100000; i++) {
			sum += i;
		}
		System.out.println("sum = " + sum);
		long end = System.currentTimeMillis(); 
		System.out.println(end - start + "ms");
	}
}
