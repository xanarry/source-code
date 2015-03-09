import java.util.Date;
import java.text.SimpleDateFormat;
public class string_format {
	public static void main(String[] args) {
		String astring = String.format("%s is %d years old, and now the time is %s", "xiongyang", 12, new Date());
		System.out.println(astring);
	}
}