import java.util.ArrayList;
import java.util.Scanner;

/*
方法就是不断删除递减序列开始的那个值
*/
public class 删除n个数后使值最小 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String strNum = in.nextLine();
		int delCount = in.nextInt();
		in.close();
		int[] num = new int[strNum.length()];
		for (int i = 0; i < strNum.length(); i++) {
			num[i] = Integer.parseInt(String.valueOf(strNum.charAt(i)));
		}

		int[] result = num;
		for (int i = 0; i < delCount; i++) {
			result = exclude(result);
		}
		
		for (int i = 0; i < result.length; i++) {
			System.out.print(result[i]);
		}
		System.out.println();
	}
	
	public static int[] exclude(int[] num) {
		int[] re = null;
		for (int i = 0; i < num.length; i++) {
			if (i == num.length-1 || num[i] > num[i + 1]) {
				num[i] = -1;
				break;
			}
		}
		int start = 0;
		while (num[start] == 0 || num[start] == -1)
			start++;
		
		if (start - num.length + 1 == 1) {
			re = new int[1];
			re[0] = 0;
		}
		
		ArrayList<Integer> arrayList = new ArrayList<>();
		for (int i = start; i < num.length; i++) {
			if (num[i] != -1) {
				arrayList.add(num[i]);
			}
		}
		
		re = new int[arrayList.size()];
		for (int i = 0; i < arrayList.size(); i++) {
			re[i] = arrayList.get(i);
		}
		
		return re;
	}

}
