class TrainTicket implements Runnable {
	int tickets = 100;
	public void run() {
		while (tickets > 0) {
			System.out.println(Thread.currentThread().getName() + "正在卖票" + tickets--);
		}
	}
}

public class 火车票 {
	public static void main(String[] args) {
		TrainTicket sallTicket = new TrainTicket();
		Thread A = new Thread(sallTicket, "窗口A ");
		A.start();
		Thread B = new Thread(sallTicket, "窗口B ");
		B.start();
		Thread C = new Thread(sallTicket, "窗口C ");
		C.start();
		Thread D = new Thread(sallTicket, "窗口D ");
		D.start();
	}
}