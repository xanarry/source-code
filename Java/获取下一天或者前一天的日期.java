package javaTest;

import java.text.ParseException;
import java.util.HashMap;

public class 获取下一天或者前一天的日期 {
	public static void main(String[] args) throws ParseException {
		getPreviousDay(2024, 3, 21);
		getPreviousDay(2024, 1, 1);
		getPreviousDay(2023, 3, 1);
		getPreviousDay(2000, 3, 1);
		
		getNextDay(2024, 3, 21);
		getNextDay(2024, 12, 30);
		getNextDay(2024, 12, 31);
		getNextDay(2024, 2, 15);
		
	}
	
	public static HashMap<String, Integer> getPreviousDay(int currentYear, int currentMonth, int currentDay) {
		HashMap<String, Integer> previousDay = new HashMap<String, Integer>();
	/*  2024-3-21--->2024-3-21
		2024-1-1--->2023-12-31
		2024-3-1--->2024-2-29
		2111-7-1--->2111-2-28
		*/
		if (currentDay > 1) {//如果日期大于1
			currentDay -= 1;
		} else {//日期 == 1;
			if (currentMonth == 3) {//如果当前月的前一个月是2二月
				if (isLeapYear(currentYear)) {//润年2月29
					currentDay = 29;
				} else {
					currentDay = 28;
				}
				//如果当前月的前一个月是31天的-1 3 5 7 8 10 12 
			} else if (currentMonth == 2 || currentMonth == 4 || currentMonth == 6 || currentMonth == 8 || currentMonth == 9 || currentMonth == 11 || currentMonth == 1) {
				currentDay = 31;
			} else {
				currentDay = 30;
			}
			currentMonth -= 1;//当前月份减一可能为0，因为存在1月（1 2 3）
			if (currentMonth == 0) {//说明刚刚减1的月是1月，应该让新的月份到12月，年份减一
				currentMonth = 12;
				currentYear -= 1;
			}
		}
		System.out.println("previous day:" + currentYear + "-" + currentMonth + "-" + currentDay);
		previousDay.put("YEAR", currentYear);
		previousDay.put("MONTH", currentMonth);
		previousDay.put("DAY_OF_MONTH", currentDay);
		
		return previousDay;
	}
	
	public static HashMap<String, Integer> getNextDay(int currentYear, int currentMonth, int currentDay) {
		HashMap<String, Integer> nextDay = new HashMap<String, Integer>();
		
		int dayLimit = 0;
		switch (currentMonth) {//获取当月天数的上限
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			dayLimit = 31;
			break;
			
		case 2:
			if (isLeapYear(currentYear)) {
				dayLimit = 29;
			} else {
				dayLimit = 28;
			}
			break;
			
		default:
			dayLimit = 30;
			break;
		}
		
		if (currentDay < dayLimit) {//如果当天不是当月的最后一天
			currentDay += 1;//日数直接加一天
		} else {//如果是当月最后一天
			currentDay = 1;
			if (currentMonth != 12) {//如果月份不是12月
				currentMonth += 1;//月份直接加1
			} else {//如果月份是12月
				currentMonth = 1;//月份变为1
				currentYear += 1;//年份加1
			}
		}
		System.out.println("next day:" + currentYear + "-" + currentMonth + "-" + currentDay);
		nextDay.put("YEAR", currentYear);
		nextDay.put("MONTH", currentMonth);
		nextDay.put("DAY_OF_MONTH", currentDay);
		return nextDay;
	}
	
	public static boolean isLeapYear(int year) {
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
			return true;
		} else {
			return false;
		}
	}
}
