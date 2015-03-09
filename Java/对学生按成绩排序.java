interface Sortable {//����ӿڰ���һ���ȽϺ���
	public boolean compare(Sortable a);
}

class Student implements Sortable {//����ѧ���࣬ʵ��sortable�ӿ�
	private String name;
	private int math;
	private int java;
	private int english;
	private int total_score;

	public Student(String name, int math, int java, int english) {
		this.name = name;
		this.math = math;
		this.java = java;
		this.english = english;
		this.total_score = math + english + java;
	}

	public String toString() {//����toString����
		return "name: " + name + " math = " + math + " java = " + java + " english = " + english + " total_score = " + total_score;
	}

	public boolean compare(Sortable a) {//ʵ�ֱȽϺ���
		Student temp = null;
		if (a instanceof Student)//ȷ�����ݹ����������ڱ���Ķ���
			temp = (Student)a;//��Ϊa��sortable���ͣ�ǿ��ת��Ϊstudent����
		else {
			System.out.println("��������");
			System.exit(0);
		}

		if (this.total_score > temp.total_score)
			return true;
		else if (this.total_score < temp.total_score)
			return false;
		else
			return true;
	}
}

class Sort {//�����������ࡣ�������һ��ѡ��������
	public static void selectSort(Sortable[] a) {
		for (int i = 0; i < a.length - 1; i++) {
			int k = i;
			for (int j = i + 1; j < a.length; j++) {
				if (a[k].compare(a[j]))
					k = j;
			}
			if (k != i) {
				Sortable temp = a[k];
				a[k] = a[i];
				a[i] = temp;
			}
		}
	}
}

public class ��ѧ�����ɼ����� {
	public static void main(String[] args) {
		final int MAX = 1000;
		Student[] stu = new Student[MAX];
		for (int i = 0; i < MAX; i++) {
			stu[i] = new Student("Student" + String.valueOf(i + 1), (int)(Math.random()*100), (int)(Math.random()*100), (int)(Math.random()*100));
		}

		Sort.selectSort(stu);

		for (Student t : stu) {
			System.out.println(t);
		}
	}
}