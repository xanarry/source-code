import java.util.*;

class Time {
	private int hour;
	private int minute;
	private int second;

	public Time() {
		hour = 0;
		minute = 0; 
		second = 0;
	}

	public Time(int h, int m, int s) {
		hour = h;
		minute = m;
		second = s;
	}

	public void self_add() {
		while (true) {//时间不断增长
			if (second < 59)//时间的进制运算
				second++;
			else {
				minute++;
				second = 0;
			}
			if (minute > 59) {//时间的进制运算
				hour++;
				minute = 0;
			}
			try {
				Thread.sleep(1000);
			}
			catch (Exception e) {
				System.out.println(e.getMessage());
			}
			display();
		}
	}

	public void display() {
		String h = "";
		String m = "";
		String s = "";
		if (hour < 10) 
			h += ("0" + String.valueOf(hour));
		else 
			h += String.valueOf(hour);

		if (minute < 10) 
			m += ("0" + String.valueOf(minute));
		else 
			m += String.valueOf(minute);

		if (second < 10) 
			s += ("0" + String.valueOf(second));
		else 
			s += String.valueOf(second);

		System.out.println(h + "-" + m + "-" + s);
	}
}

public class 时间类 {
	public static void main(String[] args) {
		Time t1 = new Time(10, 58, 45);
		t1.display();
		t1.self_add();
	}
}