import java.io.Console;
public class 从控制台获取密码的方式 {
	public static void main(String[] args) {
		Console cons = System.console();
		String username = cons.readLine("username:");
		char[] passwd = cons.readPassword("password:");
		System.out.println("username = " + username);
		System.out.println("password = " + passwd);
	}
}