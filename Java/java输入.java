import java.util.*;

public class java ‰»Î {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("what's your first name:");
		String firstname = in.next();

		System.out.println("what's your last name:");
		String lastname = in.next();

		System.out.println("what's your age:");
		int age = in.nextInt();

		System.out.println("the following is your info, please check:");
		System.out.println("firstname: " + firstname + "\n" + "lastname: " + lastname + "\n" + "age: " + age);
	}
}