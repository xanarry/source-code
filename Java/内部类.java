class Outer {
	private int i;
	private int j;

	public Outer(int i, int j) {
		this.i = i;
		this.j = j;
	}

	public int getI() {
		return i;
	}

	public int getJ() {
		return j;
	}

	class Inner {
		private int i;
		private int j;

		public Inner(int i, int j) {
			this.i = i;
			this.j = j;
		}

		public int getOuterI() {
			return Outer.this.i;
		}

		public int getInneri() {
			return i;
		}

		public int getInnerJ() {
			return j;
		}
	}
}

public class ÄÚ²¿Àà {
	public static void main(String[] args) {
		Outer out = new Outer(111, 222);
		System.out.println("outer: " + out.getI() + " " + out.getJ() + "\n");
		Outer.Inner inner = out.new Inner(333, 444);
		System.out.println("inner get outer i: " + inner.getOuterI());
		System.out.println("inner i: " + inner.getInneri());
		System.out.println("inner j: " + inner.getInnerJ());
	}	
}