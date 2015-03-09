import java.util.*;

class Circle {
	private double radius;
	final static double PI = 3.14159;
	public Circle() {
		radius = 0;
	}

	public Circle(double r) {
		radius = r;
	}

	public double getArea() {
		return PI * radius * radius;
	}

	public double getPerimeter() {
		return 2 * PI * radius;
	}

	public void show() {
		System.out.println("radius = " + radius);
		System.out.println("area = " + getArea());
		System.out.println("permeter = " + getPerimeter());
	}
}

class Cylinder extends Circle {
	private double height;

	public Cylinder(double r, double h) {
		super(r);
		height = h;
	}

	public double getVolume() {
		return super.getArea() * height;
	}

	public void showVolume() {
		System.out.println("Volume = " + getVolume());
	}
}

public class Ô²_Öù_Àà {
	public static void main(String[] args) {
		System.out.println("circle1");
		Circle  circle1 = new Circle();
		circle1.show();

		System.out.println("\ncircle2");
		Circle circle2 = new Circle(4);
		circle2.show();

		System.out.println("\ncylinder");
		Cylinder cylinder = new Cylinder(4, 3);
		cylinder.showVolume();
	}
}