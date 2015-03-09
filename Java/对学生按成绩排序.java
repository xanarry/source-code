interface Sortable {//定义接口包含一个比较函数
	public boolean compare(Sortable a);
}

class Student implements Sortable {//定义学生类，实现sortable接口
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

	public String toString() {//重载toString函数
		return "name: " + name + " math = " + math + " java = " + java + " english = " + english + " total_score = " + total_score;
	}

	public boolean compare(Sortable a) {//实现比较函数
		Student temp = null;
		if (a instanceof Student)//确保传递过来的是属于本类的对象
			temp = (Student)a;//因为a是sortable类型，强制转换为student对象
		else {
			System.out.println("参数错误！");
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

class Sort {//定义排序函数类。里面包含一个选择排序函数
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

public class 对学生按成绩排序 {
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