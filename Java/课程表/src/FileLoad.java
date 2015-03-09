import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;
import java.util.ArrayList;

public class FileLoad {
	private final String SYLLBUSNAME = "syllabus.dat";
	private String startTime = null;
	Subject[] list = new Subject[30];

	public String getStartTime() {
		return startTime;
	}

	public ArrayList<Subject> extractFile() {
		ArrayList<Subject> subjectsList = null;
		Reader reader = null;
		BufferedReader bufferedReader = null;

		try {
			reader = new FileReader(new File(SYLLBUSNAME));
		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
		}

		try {
			subjectsList = new ArrayList<Subject>(30);
			bufferedReader = new BufferedReader(reader);
			String singleSubjectInfo = null;
			int lineCount = 0;
			while ((singleSubjectInfo = bufferedReader.readLine()) != null) {
				if (lineCount == 0) {
					String split[] = singleSubjectInfo.split(" ");
					startTime = split[1];
				}
				if (lineCount > 0 && singleSubjectInfo.length() >= 10) {
					subjectsList.add(generateInfo(singleSubjectInfo));
				}
				lineCount++;
			}
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} catch (Exception e) {
			System.out.println(e.getMessage());
		} finally {
			try {
				reader.close();
				bufferedReader.close();
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
		}

		return subjectsList;
	}

	private Subject generateInfo(String singleStringSubject) {
		String[] temStrings = singleStringSubject.split(" ");
		String name = null;
		String location = null;
		ArrayList<Integer> weekRange = null;
		int classTime = 0;

		int j = 1;
		for (int i = 0; i < temStrings.length; i++) {
			if (temStrings[i].length() > 1) {
				if (j == 1) {
					name = temStrings[i];
				}
				if (j == 2) {
					location = temStrings[i];
				}
				if (j == 3) {
					for (int k = 0; k < temStrings[i].length(); k++) {
						if (Character.isDigit(temStrings[i].charAt(k))) {
							classTime = classTime * 10
									+ (int) ((temStrings[i].charAt(k) - '0'));
						}
					}
				}

				if (j == 4) {
					weekRange = getIntWeekRange(temStrings[i]);
				}
				j++;
			}
		}
		return new Subject(name, location, classTime, weekRange);
	}

	private ArrayList<Integer> getIntWeekRange(String stringWeekRange) {
		// 1-3,6-9,11-16,18
		// 1-16
		stringWeekRange += ",";
		ArrayList<Integer> weekRangeList = new ArrayList<Integer>(20);
		String[] eachNode = stringWeekRange.split(",");

		for (int i = 0; i < eachNode.length; i++) {
			if (eachNode[i].length() <= 2) {
				weekRangeList.add(Integer.parseInt(eachNode[i]));
			} else {
				String singleRange[] = eachNode[i].split("-");
				for (int j = Integer.parseInt(singleRange[0]); j <= Integer
						.parseInt(singleRange[1]); j++) {
					weekRangeList.add(j);
				}
			}
		}

		return weekRangeList;
	}

}
