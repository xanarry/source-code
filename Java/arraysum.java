import java.util.*;
public class arraysum 
{
	public static void main(String[] args) 
	{
		int len;
		Scanner in = new Scanner(System.in);
		len = in.nextInt();
		len = 10;
		int[] n = new int[len];
		int sum = 0;
		for (int i = 0; i < len; i++)
		{
			n[i] = i + 1;
		}
		for (int i : n) 
		{
			System.out.print(i + " ");
			sum = sum + i;
		}
		System.out.println();
		System.out.println(Arrays.toString(n));
		System.out.printf("the sum of the array is %d\n", sum);
	}
}