import java.io.Console;
public class �ӿ���̨��ȡ����ķ�ʽ {
	public static void main(String[] args) {
		Console cons = System.console();
		String username = cons.readLine("username:");
		char[] passwd = cons.readPassword("password:");
		System.out.println("username = " + username);
		System.out.println("password = " + passwd);
	}
}