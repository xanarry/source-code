import java.util.*;

public class imitate_login {
	public static void main(String[] args) {
		final String userName = "xiongyang";
		final String password = "123";

		Scanner in = new Scanner(System.in);
		int loginCounts = 1;

		while (true) {
			if (loginCounts > 3) {
				System.out.println("please check your UserName and Password");
				break;
			}

			System.out.print("input your login ID:");
			String loginID = in.nextLine();
			System.out.print("input your login key:");
			String loginKEY = in.nextLine();

			if (loginKEY.equals(password) && loginID.equals(userName)) {
				System.out.println("login secessful");
				break;
			}
			else {
				System.out.println("error, try again");
				loginCounts++;
			}
		}
	}
}