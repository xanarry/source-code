import java.util.*;

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

	public boolean compare(Comparable a) {
		Student temp = (Student)a;

		if (this.score > temp.score)
			return true;
		else if (this.score < temp.score)
			return false;
		else
			return true;
	}

	public String toString() {
		return "name : " + name + "\n sex : " + sex + "\nscore: " + score + "\n-------------";
	}
}

public class 对象数组排序2 {
	public static void main(String[] args) {
		final int MAX = 10;
		Student[] stu = new Student[MAX];

		char[] sexIndex = {'F', 'M'};

		for (int i = 0; i < MAX; i++) {
			String name = generateName();
			char sex = sexIndex[(int)(Math.random()*2)];
			int score = (int)(Math.random()*100);
			stu[i] = new Student(name, sex, score);
		}

		for (int i = 0; i < MAX; i++) {
			System.out.println(stu[i]);
		}
		System.out.println("sorted----------------------\n");

		for (int i = 0; i < stu.length - 1; i++) {
			for (int j = 0; j < stu.length - i - 1; j++) {
				if (stu[j].getScore() > stu[j + 1].getScore()) {
					Student temp = stu[j];
					stu[j] = stu[j + 1];
					stu[j + 1] = temp;
				}
			}
		}

		for (Student t : stu) {
			System.out.println(t);
		}
	}

	static String generateName() {
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