public class 规律分数相加 {
	public static void main(String[] args) {
		float sum = 0; 
		int i;
		for(i = 1; i <= 10; i++) {
			sum = sum + (float)1/i;
		}
		System.out.println(sum);
	}
}