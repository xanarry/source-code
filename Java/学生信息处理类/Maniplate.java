
public class Maniplate {

	public static void main(String[] args) {
		StudentList studentList = new StudentList();
		
		studentList.initialize();//初始化函数，必须使用在最前面，不然无法执行后面的操作
		studentList.displayList();//显示
		
		studentList.insertInto();//插入新的学生到学生列表中
		studentList.displayList();//显示
		
		studentList.displayAccordingtoClassNo();//输出指定班级的学生
		
		studentList.delete();//从列表中删除学生
		studentList.displayList();
		
		studentList.moveto();//移动学生到新的班级
		studentList.displayList();
	}

}
