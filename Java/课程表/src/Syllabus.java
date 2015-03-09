import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class Syllabus {
	private FileLoad loadFile = new FileLoad();
	private ArrayList<Subject> subjectsList = loadFile.extractFile();
	private Time time = new Time(loadFile.getStartTime());
	private int weekOfSemester = time.getCurrrentSemesterWeek();
	private int dayOfWeek = time.getDayofWeek();
	private String todayIs = time.getToday();
	private final String[] specificTime = { "8:00-9:45", "10:15-12:00",
			"14:10-15:55", "16:15-18:00", "19:00-20:45" };

	public void showTitle() {
		System.out.println("\t\t\t今天是" + todayIs + "  开学第" + weekOfSemester
				+ "周 星期" + dayOfWeek);
	}

	public void searchSyllabus() {
		Scanner in = new Scanner(System.in);
		int classTime = 0;

		System.out.print("\t\t请输入周次:");
		int week = in.nextInt();
		while (true) {
			if (week > 20 || week < 0) {
				System.out.print("\t\t周次输入不在有效范围内，请重新输入：");
				week = in.nextInt();
			} else {
				break;
			}
		}

		System.out.print("\t\t输入上课时间，例如星期x第y节请直接输入xy:");
		classTime = in.nextInt();
		while (true) {
			int w = classTime / 10;
			int t = classTime % 10;
			if (w >= 1 && w <= 7 && t >= 1 && t <= 5) {
				break;
			} else {
				System.out.print("\t\t时间输入不在有效范围内，请重新输入：");
				classTime = in.nextInt();
			}
		}
		in.close();

		Iterator<Subject> iterator = subjectsList.iterator();
		Subject temp = null;
		boolean find = false;
		while (iterator.hasNext()) {
			temp = iterator.next();
			if (temp.getClassTime() == classTime
					&& temp.weekRange.contains(week)) {
				find = true;
				break;
			}
		}

		if (find) {
			System.out.println("\t\t\t        第" + week + "周 第" + classTime
					+ "您有如下课程");
			System.out
					.println("\t----------------------------------------------------------------");
			System.out.println("\t\t\t       名称：" + temp.getName());
			System.out.println("\t\t\t       地点：" + temp.getLocation());
			try {
				System.out.println("\t\t\t       时间："
						+ specificTime[classTime % 10]);
			} catch (ArrayIndexOutOfBoundsException e) {
				System.out.println(e.getMessage());
			}
			System.out
					.println("\t----------------------------------------------------------------");
		} else {
			System.out.println("\t\t\t        第" + week + "第" + classTime
					+ "无课");
		}

	}

	public void checkSyllabus() {
		ArrayList<Subject> tempList = subjectsList;
		tempList.sort(null);

		Iterator<Subject> iterator = tempList.iterator();
		Subject[] subjectArray = new Subject[tempList.size()];
		int i = 0;
		while (iterator.hasNext()) {
			subjectArray[i++] = iterator.next();
		}

		ArrayList<Integer> conflictWeek = new ArrayList<Integer>(20);
		boolean isConflict = false;
		for (i = 0; i < subjectArray.length - 1; i++) {
			if (subjectArray[i].getClassTime() == subjectArray[i + 1]
					.getClassTime()) {
				Iterator<Integer> weekIterator = subjectArray[i].getWeekRange()
						.iterator();
				while (weekIterator.hasNext()) {
					Integer weekInteger = weekIterator.next();
					if (subjectArray[i + 1].getWeekRange()
							.contains(weekInteger)) {
						conflictWeek.add(weekInteger);
						isConflict = true;
					}
				}

				if (isConflict) {
					System.out.print("\t我们检查到 \"" + subjectArray[i].getName()
							+ "\" 与 \"" + subjectArray[i + 1].getName()
							+ "\" 在：");
					Iterator<Integer> conflictIterator = conflictWeek
							.iterator();
					while (conflictIterator.hasNext()) {
						System.out.print(conflictIterator.next() + " ");
					}
					System.out.println("周有上课时间的冲突，请确保您的课程文件无误！");
					conflictWeek.clear();
				}
			}
		}
	}

	public void showTodaySyllabus() {
		System.out.println("\n\t\t\t---------今日课课程----------");
		System.out
				.println("\t----------------------------------------------------------------");

		for (int classTime = 1; classTime <= 5; classTime++) {
			Iterator<Subject> iterator = subjectsList.iterator();
			Subject temp = null;
			while (iterator.hasNext()) {
				temp = iterator.next();
				if (temp.getClassTime() == dayOfWeek * 10 + classTime
						&& temp.weekRange.contains(weekOfSemester)) {
					System.out.println("\t\t\t       节次：" + "第" + classTime + "节");
					System.out.println("\t\t\t       名称：" + temp.getName());
					System.out.println("\t\t\t       地点：" + temp.getLocation());
					System.out.println("\t\t\t       时间："
							+ specificTime[classTime]);
					System.out
							.println("\t----------------------------------------------------------------");
				}
			}
		}

	}

	public void showWeekSyllabus() {
		System.out.printf("\n\t\t\t---------本周课表---------\n");
	    System.out.printf("+------+----------+----------+----------+----------+----------+----------+----------+\n");
	    System.out.printf("|      |  星期一  |  星期二  |  星期三  |  星期四  |  星期五  |  星期六  |  星期天  |\n");
		for (int classTime = 1; classTime <= 5; classTime++) { // 第几节课
			System.out.printf("+------+----------+----------+----------+----------+----------+----------+----------+\n");
		    System.out.printf("|第%d节 |", classTime);

			for (int weekday = 1; weekday <= 7; weekday++) { // 星期几

				Iterator<Subject> iterator = subjectsList.iterator();
				Subject temp = null;
				boolean isEmpty = true;
				while (iterator.hasNext()) {
					temp = iterator.next();
					if (temp.getClassTime() == weekday * 10 + classTime
							&& temp.weekRange.contains(weekOfSemester)) {
						isEmpty = false;
						break;
					}
				}

				if (!isEmpty) {
					if (temp.getName().length() <= 4) {
						System.out.printf(" %-5s|", temp.getName());
					} else {
						System.out.printf(" %-5s|",
								temp.getName().substring(0, 4));
					}
				} else {
					System.out.printf(" %-9s|", "  ");
				}
			}
			System.out.println();
		}
		System.out
				.printf("+------+----------+----------+----------+----------+----------+----------+----------+\n\n");
	}

	public void traverseList() {
		Iterator<Subject> iterator = subjectsList.iterator();
		while (iterator.hasNext()) {
			System.out.println(iterator.next());
		}
	}

}
