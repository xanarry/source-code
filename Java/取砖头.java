/*
 * 36����һ��������ȫ��36��שͷ������һ��4�飬Ů��һ��3�飬С����������һ�飬���С�������ˣ�Ů�˵ĸ���
 */
public class ȡשͷ {
	
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
