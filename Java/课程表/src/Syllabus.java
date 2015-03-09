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
		System.out.println("\t\t\t������" + todayIs + "  ��ѧ��" + weekOfSemester
				+ "�� ����" + dayOfWeek);
	}

	public void searchSyllabus() {
		Scanner in = new Scanner(System.in);
		int classTime = 0;

		System.out.print("\t\t�������ܴ�:");
		int week = in.nextInt();
		while (true) {
			if (week > 20 || week < 0) {
				System.out.print("\t\t�ܴ����벻����Ч��Χ�ڣ����������룺");
				week = in.nextInt();
			} else {
				break;
			}
		}

		System.out.print("\t\t�����Ͽ�ʱ�䣬��������x��y����ֱ������xy:");
		classTime = in.nextInt();
		while (true) {
			int w = classTime / 10;
			int t = classTime % 10;
			if (w >= 1 && w <= 7 && t >= 1 && t <= 5) {
				break;
			} else {
				System.out.print("\t\tʱ�����벻����Ч��Χ�ڣ����������룺");
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
			System.out.println("\t\t\t        ��" + week + "�� ��" + classTime
					+ "�������¿γ�");
			System.out
					.println("\t----------------------------------------------------------------");
			System.out.println("\t\t\t       ���ƣ�" + temp.getName());
			System.out.println("\t\t\t       �ص㣺" + temp.getLocation());
			try {
				System.out.println("\t\t\t       ʱ�䣺"
						+ specificTime[classTime % 10]);
			} catch (ArrayIndexOutOfBoundsException e) {
				System.out.println(e.getMessage());
			}
			System.out
					.println("\t----------------------------------------------------------------");
		} else {
			System.out.println("\t\t\t        ��" + week + "��" + classTime
					+ "�޿�");
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
					System.out.print("\t���Ǽ�鵽 \"" + subjectArray[i].getName()
							+ "\" �� \"" + subjectArray[i + 1].getName()
							+ "\" �ڣ�");
					Iterator<Integer> conflictIterator = conflictWeek
							.iterator();
					while (conflictIterator.hasNext()) {
						System.out.print(conflictIterator.next() + " ");
					}
					System.out.println("�����Ͽ�ʱ��ĳ�ͻ����ȷ�����Ŀγ��ļ�����");
					conflictWeek.clear();
				}
			}
		}
	}

	public void showTodaySyllabus() {
		System.out.println("\n\t\t\t---------���տογ�----------");
		System.out
				.println("\t----------------------------------------------------------------");

		for (int classTime = 1; classTime <= 5; classTime++) {
			Iterator<Subject> iterator = subjectsList.iterator();
			Subject temp = null;
			while (iterator.hasNext()) {
				temp = iterator.next();
				if (temp.getClassTime() == dayOfWeek * 10 + classTime
						&& temp.weekRange.contains(weekOfSemester)) {
					System.out.println("\t\t\t       �ڴΣ�" + "��" + classTime + "��");
					System.out.println("\t\t\t       ���ƣ�" + temp.getName());
					System.out.println("\t\t\t       �ص㣺" + temp.getLocation());
					System.out.println("\t\t\t       ʱ�䣺"
							+ specificTime[classTime]);
					System.out
							.println("\t----------------------------------------------------------------");
				}
			}
		}

	}

	public void showWeekSyllabus() {
		System.out.printf("\n\t\t\t---------���ܿα�---------\n");
	    System.out.printf("+------+----------+----------+----------+----------+----------+----------+----------+\n");
	    System.out.printf("|      |  ����һ  |  ���ڶ�  |  ������  |  ������  |  ������  |  ������  |  ������  |\n");
		for (int classTime = 1; classTime <= 5; classTime++) { // �ڼ��ڿ�
			System.out.printf("+------+----------+----------+----------+----------+----------+----------+----------+\n");
		    System.out.printf("|��%d�� |", classTime);

			for (int weekday = 1; weekday <= 7; weekday++) { // ���ڼ�

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
