
public class Maniplate {

	public static void main(String[] args) {
		StudentList studentList = new StudentList();
		
		studentList.initialize();//��ʼ������������ʹ������ǰ�棬��Ȼ�޷�ִ�к���Ĳ���
		studentList.displayList();//��ʾ
		
		studentList.insertInto();//�����µ�ѧ����ѧ���б���
		studentList.displayList();//��ʾ
		
		studentList.displayAccordingtoClassNo();//���ָ���༶��ѧ��
		
		studentList.delete();//���б���ɾ��ѧ��
		studentList.displayList();
		
		studentList.moveto();//�ƶ�ѧ�����µİ༶
		studentList.displayList();
	}

}
