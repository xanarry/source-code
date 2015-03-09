import java.util.*;

class Time {

	private String location;

	public Time(String s) {
		location = s;
	}

	public interface getResult {
		public String outResult();
	}

	public getResult getTime() {
		System.out.println("input h, m, s of" + location + ": ");

		int[] input = new int[3];

		Scanner in = new Scanner(System.in);

		for (int i = 0; i < 3; i++) {
			input[i] = in.nextInt();
		}


		return new getResult() {

			//////notewortht-->////////
			private int testInitializedVar1;
			private int testInitializedVar2;

			{
				testInitializedVar1 = 111;
				testInitializedVar2 = 222;
			}
			//////<--noteworthy/////////

			/*the above can not write as follows like */
			/*
			{
				private int testInitializedVar1 = 111;
				private int testInitializedVar2 = 222;
			}
			*/

			public String outResult() {
				return location + " time: " + input[0] + "-" + input[1] + "-" + input[2] + "\ntestInitializedVar1 = "
				 		+ testInitializedVar1 + "\ntestInitializedVar2 = " + testInitializedVar2;
			}
		};
	}
}

public class 匿名内部类 {
	public static void main(String[] args) {
		Time t1 = new Time("beijing");
		System.out.println(t1.getTime().outResult());
	}
}