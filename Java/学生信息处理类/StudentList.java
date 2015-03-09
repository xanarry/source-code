import java.util.*;

//ѧ���б��࣬�������ɸ�student��Ķ���
public class StudentList {
	ArrayList<Student> studentsList = new ArrayList<Student>(100);//ʹ��ArrayList�������鴦���б�
	private Scanner in = new Scanner(System.in);//�������������Scanner����

	public void initialize() {//��ʼ������list���������Ĭ��Ԫ��
		studentsList.add(new Student("111", "A", 'F', 18, 2));
		studentsList.add(new Student("222", "B", 'M', 19, 2));
		studentsList.add(new Student("333", "C", 'F', 20, 5));
	}

	public void displayList() {//���������Ϣ
		if (studentsList.isEmpty()) {//�ж��б��Ƿ�Ϊ��
			System.out.println("no element in this arraylist");
			return;
		}
		
		Iterator<Student> iterator = studentsList.listIterator();//��ʼ��������
		while (iterator.hasNext()) {
			System.out.println(iterator.next());//�����б�
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

	public void delete() {//ɾ��ѧ��
		System.out.println("---test delete---\ninput the ID of the student you wanna delete:");
		System.out.println("");
		String delID = in.nextLine();//����Ŀ��ID

		Iterator<Student> iterator = studentsList.iterator();
		while (iterator.hasNext()) {//����
			if (iterator.next().getID().equals(delID)) //����
				iterator.remove();//ɾ��
		}
	}

	public void moveto() {
		System.out.println("---test moveto---\nwhitch student you wanna remove to new class: ");
		String removeId = in.nextLine();//��ȡҪ�޸ĵ�ѧ��
		System.out.println("input new classNo:");
		int newClassNo = in.nextInt();//�µİ༶

		Iterator<Student> iterator = studentsList.iterator();
		int i = 0;//��¼�±�
		while (iterator.hasNext()) {//�����б�
			Student tempsStudent = iterator.next();
			if (tempsStudent.getID().equals(removeId)) {//����
				tempsStudent.setClassNo(newClassNo);//�޸�
				studentsList.set(i, tempsStudent);//����
			}
			i++;
		}
	}

	public void displayAccordingtoClassNo() {//���ָ���༶��ѧ��
		System.out.println("---test displayAccordingtoClassNo---\ninput classNo:");
		int classNo = in.nextInt();
		Iterator<Student> iterator = studentsList.iterator();

		while (iterator.hasNext()) {
			Student tempsStudent = iterator.next();
			if (tempsStudent.getClassNo() == classNo) //�������������ѧ��
				System.out.println(tempsStudent);
		}
	}
}
