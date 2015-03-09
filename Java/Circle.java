import java.util.*;
public class Circle 
{
	private int radius;
	final double PI = 3.14159;

	public void setR()
	{
		System.out.print("input a R:");
		Scanner in = new Scanner(System.in);
		int r = in.nextInt();
	}

	public int getR()
	{
		return radius;
	}

	public Circle(){}

	public Circle(int r)
	{
		radius = r;
	}

	public double Area()
	{
		return PI * radius * radius;
	}

	public double paremeter()
	{
		return 2 * PI * radius;
	}


	public static void main(String[] args) 
	{
		Circle c = new Circle(4);
		System.out.println(c.Area());
		System.out.println(c.paremeter());

	}
}