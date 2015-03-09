import java.util.Calendar;

public class Time {

	private int year;
	private int month;
	private int day;

	public int currentSemesterWeek;

	public Time(int year, int month, int day) {
		this.year = year;
		this.month = month;
		this.day = day;
	}

	public Time(String startTime) {// 20140824
		int y = Integer.parseInt(startTime.substring(0, 4));
		int m = Integer.parseInt(startTime.substring(4, 6));
		int d = Integer.parseInt(startTime.substring(6, 8));
		this.year = y;
		this.month = m;
		this.day = d;
	}

	public int getYear() {
		return year;
	}

	public void setYear(int year) {
		this.year = year;
	}

	public int getMonth() {
		return month;
	}

	public void setMonth(int month) {
		this.month = month;
	}

	public int getDay() {
		return day;
	}

	public void setDay(int day) {
		this.day = day;
	}

	public int getCurrentYearWeek() {
		return Calendar.getInstance().get(Calendar.WEEK_OF_YEAR);
	}

	public int getCurrrentSemesterWeek() {
		int dayOfStart = getDayOfYear();

		int currentSemesterWeek = getCurrentYearWeek() - 1 - dayOfStart / 7;
		return currentSemesterWeek;
	}

	public int getDayofWeek() {
		Calendar now = Calendar.getInstance();
		int dayOfWeek = now.get(Calendar.DAY_OF_WEEK);
		return dayOfWeek - 1;
	}

	public String getToday() {
		Calendar calendar = Calendar.getInstance();
		StringBuffer sb = new StringBuffer();
		sb.append(calendar.get(Calendar.YEAR));
		sb.append("-");
		sb.append(calendar.get(Calendar.MONTH));
		sb.append("-");
		sb.append(calendar.get(Calendar.DATE));
		return sb.toString();
	}

	public int getDayOfYear() {
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
				break;
			}
		}
		days += day;

		return days;
	}

	private boolean isLeapYear(int year) {
		if (year % 4 == 0 && year % 400 != 0 || year % 400 == 0)
			return true;
		return false;
	}
}
