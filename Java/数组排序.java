 import java.util.*;

 public class �������� {
 	public static void main(String[] args) {
 		int[] a = new int[10];
 		for (int i = 0; i < 10; i++) {
 			a[i] = (int)(Math.random()*100);
 			System.out.print(a[i] + " ");
 		}
 		System.out.println();
 		
 		Arrays.sort(a);//����Arrays���е�������

 		for (int t : a) {
 			System.out.print(t + " ");
 		}

 	}
 }