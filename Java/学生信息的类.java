import java.util.*;

class Student {
	private String no;
	private String name;
	private char sex;
	private int age;
	private int java;

	public Student(String n, String na, char s, int a, int j) {
		no = n;
		name = na;
		sex = s;
		age = a;
		java = j;
	}

	public String getNo() {
		return no;
	}

	public String getName() {
		return name;
	}

	public char getSex() {
		return sex;
	}

	public int getAge() {
		return age;
	}

	public int getJava() {
		return java;
	}

}

public class ѧ����Ϣ���� {
	public static void main(String[] args) {
		Student[] st = new Student[5];
		st[0]=new Student("09zc01", "����", 'F', 19, 94);
		st[1]=new Student("09zc02", "����", 'M', 20, 85);
		st[2]=new Student("09zc03", "����", 'F', 18, 96);
		st[3]=new Student("09zc04", "����", 'M', 17, 90);
		st[4]=new Student("09zc05", "����", 'F', 21, 88);
		
		int max = 0; 
		int min = 100;
		int sum = 0;

		for (int i = 0; i < 5; i++) {

			if (st[i].getJava() > max)
				max = st[i].getJava();
			if (st[i].getJava() < min)
				min = st[i].getJava();

			sum += st[i].getJava();

			System.out.println("ѧ����ţ�"+st[i].getNo()+", ������"+st[i].getName()+", �Ա�"+st[i].getSex()+", ���䣺"+st[i].getAge()+", Java��ѧ�֣�"+st[i].getJava());
		}
		System.out.println("max = " + max);
		System.out.println("min = " + min);
		System.out.println("sum = " + sum);
		System.out.println("average = " + sum/5);
	}
}