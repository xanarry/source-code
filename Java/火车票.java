class TrainTicket implements Runnable {
	int tickets = 100;
	public void run() {
		while (tickets > 0) {
			System.out.println(Thread.currentThread().getName() + "������Ʊ" + tickets--);
		}
	}
}

public class ��Ʊ {
	public static void main(String[] args) {
		TrainTicket sallTicket = new TrainTicket();
		Thread A = new Thread(sallTicket, "����A ");
		A.start();
		Thread B = new Thread(sallTicket, "����B ");
		B.start();
		Thread C = new Thread(sallTicket, "����C ");
		C.start();
		Thread D = new Thread(sallTicket, "����D ");
		D.start();
	}
}