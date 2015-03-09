public class runnable implements Runnable {
	private String name;
	public runnable(String n) {
		name = n;
	}
	public void run() {
		for (int i = 0; i < 10; i++) {
			System.out.println("now " + name + " run to " + i);
		}
	}
	public static void main(String[] args) {
		runnable a = new runnable("aaaaa");
		runnable b = new runnable("b");
		runnable c = new runnable("c");
	//	a.run();
	//	b.run();
	//	c.run();
		Thread thread1 = new Thread(a, "t1");
		Thread thread2 = new Thread(b, "t2");
		thread1.start();
		thread2.start();
	}
}