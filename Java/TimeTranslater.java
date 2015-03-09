import java.util.*;

public class TimeTranslater {//outer class
	private int timelast;

	public TimeTranslater(int length) {//constructor for outer class
		this.timelast = length;
	}

	public interface Conduct {//specify a interface
		public String calculate();
	}

	public Conduct getResult() {//a method of outer class including a local inner class

		//inner class start
		class HMS implements Conduct{//implements the interface of conduct for inner class 
			private int hour;
			private int minute;
			private int second;
			private int total;

			public HMS(int timelast) {
				hour = 0;
				minute = 0;
				second = 0;
				total = timelast;
			}

			public String calculate() {
				if (total >= 3600) {
					hour = total/3600;
					minute = (total - hour*3600)/60;
					second = total%60;
				}
				else if (total >= 60) {
					hour = 0;
					minute = total/60;
					second = total%60;
				} else {
					hour = 0;
					minute = 0;
					second = total;
				}

				return hour + ":" + minute + ":" + second;
			}
		}//inner class end

		return new HMS(timelast);//return the new HMS as result
	}

	public static void main(String[] args) {
		TimeTranslater t1 = new TimeTranslater(10203);
		Conduct get = t1.getResult();
		System.out.println(get.calculate());
	}
}