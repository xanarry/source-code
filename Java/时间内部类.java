class GenerateTime{
	public GenerateTime(int y, int m, int d){
		create(y, m, d);
	}

	private void create(final int x, final int y, final int z) {
		class Time {
			private int year;
			private int month;
			private int day;

			public Time(int a, int b, int c) {
				year = a;
				month = b;
				day = c;
			}

			public String toString() {
				return "Date[" + year + "-" + month + "-" + day + "]";
			}
		}

		Time t1 = new Time(x, y, z);
		System.out.println(t1);
	}
}

public class 时间内部类 {
	public static void main(String[] args) {
		new GenerateTime(2014, 10, 11);
	}
}