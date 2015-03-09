import java.util.*;

//学生列表类，包含若干个student类的对象
public class StudentList {
	ArrayList<Student> studentsList = new ArrayList<Student>(100);//使用ArrayList泛型数组处理列表
	private Scanner in = new Scanner(System.in);//创建输入所需的Scanner对象

	public void initialize() {//初始化是想list中添加三个默认元素
		studentsList.add(new Student("111", "A", 'F', 18, 2));
		studentsList.add(new Student("222", "B", 'M', 19, 2));
		studentsList.add(new Student("333", "C", 'F', 20, 5));
	}

	public void displayList() {//输出所有信息
		if (studentsList.isEmpty()) {//判断列表是否为空
			System.out.println("no element in this arraylist");
			return;
		}
		
		Iterator<Student> iterator = studentsList.listIterator();//初始化迭代器
		while (iterator.hasNext()) {
			System.out.println(iterator.next());//遍历列表
		}
	}

	public void insertInto() {
		System.out.println("---test insert into list---\ninput new studnet's name:");
		String newName = in.nextLine();
		System.out.println("input new student's ID:");
		String newID = in.nextLine();
		System.out.println("input new student's sex:");
		char newSex = in.nextLine().charAt(0);
		System.out.println("input new student's age:");
		int newAge = in.nextInt();
		System.out.println("input new student's class:");
		int newClassNo = in.nextInt();

		studentsList.add(new Student(newID, newName, newSex, newAge, newClassNo));
	}

	public void delete() {//删除学生
		System.out.println("---test delete---\ninput the ID of the student you wanna delete:");
		System.out.println("");
		String delID = in.nextLine();//输入目标ID

		Iterator<Student> iterator = studentsList.iterator();
		while (iterator.hasNext()) {//遍历
			if (iterator.next().getID().equals(delID)) //查找
				iterator.remove();//删除
		}
	}

	public void moveto() {
		System.out.println("---test moveto---\nwhitch student you wanna remove to new class: ");
		String removeId = in.nextLine();//获取要修改的学号
		System.out.println("input new classNo:");
		int newClassNo = in.nextInt();//新的班级

		Iterator<Student> iterator = studentsList.iterator();
		int i = 0;//记录下标
		while (iterator.hasNext()) {//遍历列表
			Student tempsStudent = iterator.next();
			if (tempsStudent.getID().equals(removeId)) {//查找
				tempsStudent.setClassNo(newClassNo);//修改
				studentsList.set(i, tempsStudent);//插入
			}
			i++;
		}
	}

	public void displayAccordingtoClassNo() {//输出指定班级的学生
		System.out.println("---test displayAccordingtoClassNo---\ninput classNo:");
		int classNo = in.nextInt();
		Iterator<Student> iterator = studentsList.iterator();

		while (iterator.hasNext()) {
			Student tempsStudent = iterator.next();
			if (tempsStudent.getClassNo() == classNo) //输出满足条件的学生
				System.out.println(tempsStudent);
		}
	}
}
