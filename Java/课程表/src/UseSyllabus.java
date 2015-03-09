import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class UseSyllabus {

	public static void main(String[] args) {
		Syllabus syllabus = new Syllabus();
		syllabus.checkSyllabus();
		syllabus.showTitle();
		syllabus.showTodaySyllabus();
		
		//syllabus.showWeekSyllabus();
		// syllabus.traverseList();

		System.out.print("\t\t\t\t≤È—Ø«Î∞¥1:");

		BufferedReader bufferedReader = new BufferedReader(
				new InputStreamReader(System.in));
		String chooseString = null;

		try {
			chooseString = bufferedReader.readLine();
		} catch (IOException e) {
			System.out.println(e.getMessage());
		}

		int choose = Integer.parseInt(chooseString);
		if (choose == 1) {
			syllabus.searchSyllabus();
		}
	}

}
