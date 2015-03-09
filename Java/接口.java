
interface shape {
	double area();
	double perimeter();
}

class rectangle implements shape {
	private double a;
	private double b;
	public rectangle(){
		a = 0;
		b = 0;
	}
	public rectangle(double a, double b) {
		this.a = a;
		this.b = b;
	}
	public double area() {
		return a * b;
	}
	public double perimeter() {
		return 2 * (a + b);
	}
}

public class ½Ó¿Ú {
	public static void main(String[] args) {
		rectangle r1 = new rectangle();
		rectangle r2 = new rectangle(3, 4);
		System.out.println("r1.area() = " + r1.area() + "\nr1.perimeter() = " + r1.perimeter());
		System.out.println("r2.area() = " + r2.area() + "\nr2.perimeter() = " + r2.perimeter());
	}
}