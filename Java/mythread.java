public class mythread extends Thread {
	public mythread() {
		super();
	}
	public mythread(String n) {
		setName(n);
	}
	public void run() {
		System.out.println(this.getName() + " running");
	}
	public static void main(String[] args) {
		System.out.println(Thread.currentThread().getName() + "  is running");
		mythread thread1 = new mythread("thread 1");
		mythread thread2 = new mythread("thread 2");
		mythread thread3 = new mythread("thread 3");
		mythread thread4 = new mythread("thread 4");

		thread1.start();
		thread2.start();
		thread3.start();
		thread4.start();
	}
}