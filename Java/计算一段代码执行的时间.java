public class 计算一段代码执行的时间 {
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
