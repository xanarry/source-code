import java.util.Date;
import java.text.SimpleDateFormat;
public class Time_format_control {
	public static void main(String[] args) {
		System.out.printf("%1$s %2$tF %2$te %3$tm\n", "Date is: ", new Date(), new Date());
	}
}