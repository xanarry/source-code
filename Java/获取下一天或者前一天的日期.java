package javaTest;

import java.text.ParseException;
import java.util.HashMap;

public class ��ȡ��һ�����ǰһ������� {
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
		if (currentDay > 1) {//������ڴ���1
			currentDay -= 1;
		} else {//���� == 1;
			if (currentMonth == 3) {//�����ǰ�µ�ǰһ������2����
				if (isLeapYear(currentYear)) {//����2��29
					currentDay = 29;
				} else {
					currentDay = 28;
				}
				//�����ǰ�µ�ǰһ������31���-1 3 5 7 8 10 12 
			} else if (currentMonth == 2 || currentMonth == 4 || currentMonth == 6 || currentMonth == 8 || currentMonth == 9 || currentMonth == 11 || currentMonth == 1) {
				currentDay = 31;
			} else {
				currentDay = 30;
			}
			currentMonth -= 1;//��ǰ�·ݼ�һ����Ϊ0����Ϊ����1�£�1 2 3��
			if (currentMonth == 0) {//˵���ոռ�1������1�£�Ӧ�����µ��·ݵ�12�£���ݼ�һ
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
		switch (currentMonth) {//��ȡ��������������
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
		
		if (currentDay < dayLimit) {//������첻�ǵ��µ����һ��
			currentDay += 1;//����ֱ�Ӽ�һ��
		} else {//����ǵ������һ��
			currentDay = 1;
			if (currentMonth != 12) {//����·ݲ���12��
				currentMonth += 1;//�·�ֱ�Ӽ�1
			} else {//����·���12��
				currentMonth = 1;//�·ݱ�Ϊ1
				currentYear += 1;//��ݼ�1
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
