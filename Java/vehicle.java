import java.util.*;

class Car {
	private int speed;
	private int size;

	public Car(int spd, int si) {
		speed = spd;
		size = si;
	}

	public void move() {
		System.out.println("car is running");
	}

	public void setSpeed(int spd) {
		speed = spd;
	}

	public void speedUp(int n) {
		speed += n;
	}

	public void speedDown(int n) {
		speed -= n;
	}

	public void display() {
		System.out.println("speed = " + speed);
		System.out.println("size = " + size);
	}
}

public class vehicle {
	public static void main(String[] args) {
		Car car = new Car(1000, 10);
		car.display();
		car.move();
	}
}