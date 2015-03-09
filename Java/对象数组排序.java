import java.util.Arrays;
import java.util.Comparator;

class Student {
	private String name;
	private char sex;
	private int score;

	public Student(String name, char sex, int score) {
		this.name = name;
		this.sex = sex;
		this.score = score;
	}

	public int getScore() {
		return score;
	}

	public String toString() {
		return "name : " + name + "\n sex : " + sex + "\nscore: " + score + "\n-------------";
	}
}

class stuCompare implements Comparator {//实现接口
	public int compare(Object a, Object b) {
		return ((Student)a).getScore() - ((Student)b).getScore();
	}
}

public class 对象数组排序 {
	public static void main(String[] args) {
		final int MAX = 10;
		Student[] stu = new Student[MAX];

		char[] sex_index = {'F', 'M'};

		for (int i = 0; i < MAX; i++) {
			String name = generatName();
			char sex = sex_index[(int)(Math.random()*2)];
			int score = (int)(Math.random()*100);
			stu[i] = new Student(name, sex, score);
		}

		for (int i = 0; i < MAX; i++) {
			System.out.println(stu[i]);
		}

		System.out.println("sorted----------------------");
		Arrays.sort(stu, new stuCompare());//警告来源////////////////

		for (Student t : stu) {
			System.out.println(t);
		}
	}

	//生成姓名
	static String generatName() {
		char[] letter = new char[26];
		int index = 0;
		for (char i = 'a'; i <= 'z'; i++) {
			letter[index] = i;
			index++;
		}	

		int len = (int)(Math.random()*3) + 3;
		char[] name = new char[len];
		for (int i = 0; i < len; i++) {
			name[i] = letter[(int)(Math.random()*26)];
		}

		return new String(name);
	}
}