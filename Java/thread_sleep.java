public class thread_sleep extends Thread {
	public thread_sleep(String n) {
		setName(n);
	}
	public void run() {
		int i = 1; 
		while (i <= 10) {
			try {
				System.out.println(getName() + " running " + i);
				Thread.sleep(1000);//使用sleep必须要做异常处理
				i++;
			}
			catch (InterruptedException e) {
				e.getMessage();
			}
		}
	}
	public static void main(String[] args) {
		thread_sleep t1 = new thread_sleep("thread 1");
		thread_sleep t2 = new thread_sleep("thread 2");
		t1.start();
		t2.start();
	}
}