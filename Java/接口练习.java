interface Vehicle {
	public abstract void start(boolean a);
	public abstract void stop(boolean b);
}

class Bike implements Vehicle {
	private String name;
	private int speed;

	public Bike(int s) {
		name = "Bike";
		speed = s;
	}

	public void start(boolean a) {
		if (a)
			speed = 40;
		else 
			speed = 0;
	}

	public void stop(boolean b) {
		if (b)
			speed = 0;
		else
			speed = 40;
	}

	public void display() {
		System.out.println("this is " + name);
		System.out.println("now running speed is " + speed);
	}
} 

class Bus implements Vehicle {
	private String name;
	private int speed;

	public Bus(int s) {
		name = "Bus";
		speed = s;
	}

	public void start(boolean a) {
		if (a)
			speed = 100;
		else 
			speed = 0;
	}

	public void stop(boolean b) {
		if (b)
			speed = 0;
		else
			speed = 100;
	}

	public void display() {
		System.out.println("this is " + name);
		System.out.println("now running speed is " + speed);
	}
}

public class ½Ó¿ÚÁ·Ï° {
	public static void main(String[] args) {
		System.out.println("BIKE");
		Bike bike = new Bike(35);
		bike.display();
		bike.stop(true);
		bike.display();

		System.out.println("\nBUS");
		Bus bus = new Bus(60);
		bus.display();
		bus.stop(true);
		bus.display();
	}
}