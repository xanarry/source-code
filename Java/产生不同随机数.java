import java.util.*;
public class 产生不同随机数 {
	public static void main(String[] args) {
		int k = 6;//how many number will output
		int n = 50;//max vaule of the output number

		int[] numbers = new int[n];//value array for random generate

		for (int i = 0; i < numbers.length; i++) {
			numbers[i] = i + 1;//from 1 to n;
		}

		int[] result = new int[k];//array for output

		for (int i = 0; i < result.length; i++) {
			int r = (int)(Math.random() * n);//random will generate a float less than 1, and r is from 0 to n - 1;
			result[i] = numbers[r];//r is a index of numbers

			numbers[r] = numbers[n - 1];//full fill a new number of the index has been used;
			n--;//in case to full fill with same numbers
		}

		Arrays.sort(result);
		
		for (int r : result) {
			System.out.println(r);
		}

		System.out.println("the range of random numbers");
		for (int i = 0; i < 100; i++)
		{
			System.out.print((int)(Math.random() * 50) + " ");
		}
	}
}