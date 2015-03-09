public class 线程匿名内部类1 {
	public static void main(String[] args) {
		
		Runnable r = new Runnable() {
			public void run() {
				System.out.println("Thread is running!");
				for (int i = 0; i < 10; i++) {
					System.out.println(i);
				}
			}
		};

		Thread p = new Thread(r);
		p.start();
	}
}