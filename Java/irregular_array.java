public class irregular_array 
{
	public static void main(String[] args) 
	{
		final int MAX = 10;
		int[][] a = new int[MAX][];//首先定义这个二维数组包含多少个数组在其中
		for (int i = 0; i < MAX; i++) 
		{
			a[i] = new int[i + 1];//为二维数组中的每一个数组分配大小
		}

		for (int i = 0; i < a.length; i++) 
		{
			for (int k = 0; k < a[i].length; k++) 
			{
				a[i][k] = k;//赋值
			}
		}

		for (int[] t1 : a) 
		{
			for (int t2 : t1) 
			{
				System.out.print(t2 + " ");
			}
			System.out.println();
		}
	}
}