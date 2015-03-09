import java.util.*;

public class 分解质因数 {
	public static void main(String[] args) {
		System.out.print("input a number:");
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		System.out.print(n + " = ");

		int i = 2;//从最小质数2开始除起
		while (n != i) {//当被除数和除数不相等的时候就继续计算
			if (n%i == 0) {//如果这个数能被i整出
				System.out.print(i + "*");//输出这个数
				n /= i;//对n取整
			}
			else//假如不能被当前这个数整除，则应该让除数加1
				i++;
		}
		System.out.print(i);
		System.out.println();
	}
}