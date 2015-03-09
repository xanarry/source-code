abstract class shape {//抽象类
	public abstract double area();
	public abstract double perimeter();
}

class triangle extends shape {
	private double a;
	private double b;
	private double c;

	public triangle() {}
	public triangle(double a, double b, double c) {
		this.a = a;
		this.b = b;
		this.c = c;
	}
	public double area() {//覆盖抽象类中的方法
		double tmp = (a + b + c)/2;
		double s = Math.sqrt(tmp * (tmp - a) * (tmp - b) * (tmp - c));
		return s;
	}
	public double perimeter() {//覆盖抽象类中的方
		return a + b + c;
	}
}

class square extends shape {
	private double a;

	public square() {}
	public square(double a) {
		this.a = a;
	}
	public double area() {
		return a * a;
	}
	public double perimeter() {
		return a * 4;
	}
}

class rectangle extends shape {
	private double a;
	private double b;

	public rectangle(){}
	public rectangle(double a, double b) {
		this.a = a;
		this.b = b;
	}
	public double area() {
		return a * b;
	}
	public double perimeter() {
		return (a + b) * 2;
	}
}

class circle extends shape {
	private double radius;
	public circle() {}
	public circle(double r) {
		radius = r;
	}
	final double PI = 3.1415926;
	public double area() {
		return PI * radius * radius;
	}
	public double perimeter() {
		return PI * 2 * radius;
	}
	public double getRadius() {
		return radius;
	}
}

class cylinder extends circle {
	private double height;

	public cylinder() {}
	public cylinder(double r, double h) {
		super(r);
		height = h;
	}
	public double area() {
		return 2 * PI * 2 * super.getRadius() + 2 * PI * super.getRadius() * height;
	}
	public double perimeter() {
		return super.perimeter();
	}
}

public class 几何图形 {
	public static void main(String[] args) {
		triangle tri = new triangle(3, 4, 5);
		System.out.println("triangle area:" + tri.area());
		System.out.println("triangle perimeter:" + tri.perimeter() + "\n");

		square sq = new square(4);
		System.out.println("square area:" + sq.area());
		System.out.println("square perimeter:" + sq.perimeter() + "\n");

		rectangle rct = new rectangle(3, 4);
		System.out.println("rectangle area:" + rct.area());
		System.out.println("rectangle perimeter:" + rct.perimeter() + "\n");

		circle ci = new circle(4);
		System.out.println("circle area:" + ci.area());
		System.out.println("circle perimeter:" + ci.perimeter() + "\n");

		cylinder cy = new cylinder(3, 4);
		System.out.println("cylinder area:" + cy.area());
		System.out.println("cylinder perimeter:" + cy.perimeter() + "\n");
	}
}