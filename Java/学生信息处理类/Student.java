//类Student，包含的属性有学号、姓名、性别、年龄、班号等，方法有toString、更改年龄、更改班号
public class Student {
	private String ID;
	private String name;
	private char sex;
	private int age;
	private int classNo;

	public Student() {
	}

	public Student(String id, String n, char s, int a, int c) {//构造函数
		ID = id;
		name = n;
		sex = s;
		age = a;
		classNo = c;
	}

	@Override
	public String toString() {
		return "Student [ID=" + ID + ", name=" + name + ", sex=" + sex
				+ ", age=" + age + ", classNo=" + classNo + "]";
	}

	public String getID() {
		return ID;
	}

	public void setID(String iD) {
		ID = iD;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public int getClassNo() {
		return classNo;
	}

	public void setClassNo(int classNo) {
		this.classNo = classNo;
	}

}
