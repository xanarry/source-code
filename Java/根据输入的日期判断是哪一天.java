import java.util.*;

public class 根据输入的日期判断是哪一天 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input year: ");
		int year = in.nextInt();
		System.out.print("input month: ");
		int month = in.nextInt();
		System.out.print("input day: ");
		int day = in.nextInt();
		System.out.printf("date you input is: %d-%d-%d\n", year, month, day);

		int days = 0;

		for (int i = 1; i < month; i++) {
			switch (i) {
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					days += 31;
					break;

				case 2:
					if (isLeapYear(year))
						days += 29;
					else
						days += 28;
					break;

				default:
					days += 30;
			}
		}
		days += day;

		System.out.println("the date is " + days + "th day of this year");
	}

	static boolean isLeapYear(int year) {
		if ((year%4 == 0) && (year%100 != 0) || (year%400 == 0))
			return true;
		else
			return false;
	}
}