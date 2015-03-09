public class cylinder_extends_circle {
	public static void main(String[] args) {
		Circle[] c = new Circle[3];
		for (int i = 0; i < 3; i++) {
			c[i] = new Circle(i + 2);
		}
		
		for (Circle t : c) {
			System.out.println("r = " + t.getRadius() + ", area = " + t.area());
		}

		System.out.println("----------------------");

		Cylinder[] cy = new Cylinder[3];
		for (int i = 0; i < 3; i++) {
			cy[i] = new Cylinder(i + 2, i + 1);
		}

		for (Cylinder t : cy) {
			System.out.println("r = " + t.getRadius() + ", height = " + t.getHeight() + ", volume = " + t.volume());
		}
	}
}

class Circle {
	static final double PI = 3.14;
	private double radius;
	public Circle() {
		radius = 0;
	}
	public Circle(double r) {
		radius = r;
	}
	public double area() {
		return PI * radius * radius;
	}
	public double getRadius() {
		return radius;
	}
}

class Cylinder extends Circle {
	private double height;

	public Cylinder(double r, double h) {
		super(r);
		height = h;
	}
	public double volume() {
		return super.area() * height;
	}

	public double getHeight() {
		return height;
	}

	public double getRadius() {
		return super.getRadius();
	}
}
