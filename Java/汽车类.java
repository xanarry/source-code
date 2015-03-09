import java.util.*;

class Auto {
	private int wheels;
	private String color;
	private int weight;
	protected int speed;

	public Auto(int wh, String c, int we, int s) {
		wheels = wh;
		color = c;
		weight = we;
		speed = s;
	}

	public void speedUp() {
		System.out.println("Auto has speed up");
	}

	public void speedDown() {
		System.out.println("Auto has speed down");
	}

	public void stop() {
		speed = 0;
		System.out.println("Auto has stop");
	}

	public void display() {
		System.out.println("wheels = " + wheels);
		System.out.println("color = " + color);
		System.out.println("weight = " + weight);
		System.out.println("speed = " + speed);
	}
}

class Car extends Auto {
	private String aircondition;
	private String CD;

	public Car(int wh, String c, int we, int s, String ai, String cd) {
		super(wh, c, we ,s);
		aircondition = ai;
		CD = cd;
	}

	public void speedUp() {
		System.out.println("Car has speed up");
	}

	public void speedDown() {
		System.out.println("Car has speed down");
	}

	public void stop() {
		speed = 0;
		System.out.println("Car has stop");
	}

	public void display() {
		super.display();
		System.out.println("aircondition = " + aircondition);
		System.out.println("CD" + CD);
	}
}

public class Æû³µÀà {
	public static void main(String[] args) {
		System.out.println("Auto");
		Auto auto = new Auto(4, "red", 10000, 70);
		auto.display();

		System.out.println("\ncar");
		Car car = new Car(6, "blue", 15000, 80, "Media", "Jay-z");
		car.display();

		System.out.println("\nauto = car");
		auto = car;
		auto.display();
	}
}