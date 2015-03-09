/*
 * 36个人一次性拿走全部36块砖头，男人一次4块，女人一次3块，小孩两个人拿一块，求出小孩，男人，女人的个数
 */
public class 取砖头 {
	
	 public static void main(String[] args) {
		 for (int f = 0; f < 10; f++) {
			 for (int m = 0; m < 14; m++) {
				 for (int k = 0; k < 73; k++) {
					 if ((f * 4 + m * 3 + k * 0.5 == 36) && (f + m + k == 36)) {
						 System.out.println(f + " " + m + " " + k);
					 }
				 }
			 }
		 }
	 }
	 
}
