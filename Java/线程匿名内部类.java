public class 线程匿名内部类 {
	public static void main(String[] args) {

		Thread p = new Thread() {//同时定义实现类
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