public class �߳������ڲ��� {
	public static void main(String[] args) {

		Thread p = new Thread() {//ͬʱ����ʵ����
			public void run() {
				System.out.println("Thread is running!");
				for (int i = 0; i <= 10; i++) {
					System.out.println(i);
				}
			}
		};

		p.start();
	}
}