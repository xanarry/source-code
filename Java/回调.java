class General {
	public callable b1;

	public void getReady(callable a) {
		b1 = a;
	}

	public void giveOrder() {
		b1.fire();
	}
}

interface callable {
	void fire();
}

class Base implements callable {
	public void fire() {
		System.out.println("fire American");
	}
}

public class »Øµ÷ {
	public static void main(String[] args) {
		General g = new General();
		Base b = new Base();
		g.getReady(b);
		g.giveOrder();
	}
}