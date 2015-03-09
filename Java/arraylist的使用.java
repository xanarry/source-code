import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;

class Student implements Comparable<Student> {//��Ϊ��ArrayList��ʹ���˷��ͣ�����Ҫ�ڴ���<>�������ͣ������Ƕ�String��ʵ�ֵĽӿھ�дString  
    String name;  
    int age;  
  
    public Student(String name, int age) {  
        super();  
        this.name = name;  
        this.age = age;  
    }  
      
    public int compareTo(Student tempStudent) {//��д�ӿ��еĺ���  
    	if (this.age != tempStudent.age) {//�����䲻��ͬʱ����ֻ������Ĵ�С��ѧ����������  
        	return this.age - tempStudent.age;//�������ߵ�˳�����ʵ���������ǽ���  
    	}  
    	else {//�������ѧ����������ͬ����ô���ǾͰ�����������  
        	if (!this.getName().equals(tempStudent.getName())) {//���ǰ������ĸ��һ�������ǾͲ��ܽ��бȽϣ�����Ҫ�Ե�һ����ͬ����ĸ���бȽ�  
            	int i = 0;  
            	while (i < this.name.length() && i < tempStudent.getName().length()) {//ʹ��ѭ���ҵ���һ����ͬ����ĸ  
                	if (this.name.charAt(i) != tempStudent.getName().charAt(i))  
                	    break;  
                	i++;  
            	}  
            	return this.name.charAt(i) - tempStudent.getName().charAt(i);//�������ֵıȽ�ֵ  
       		}  
        	else//��������ͬ��  
            	return -1;//˳�㷵��һ��ֵ����Ϊ�ⲻ��Ӱ������Ľ����ֻ��Ϊ����ǰ���if����  
    	}
    }  
  
	public String toString() {
		return "name=" + name + ", age=" + age;
	}
	
	public String getName() {
		return this.name;
	}
}

public class arraylist��ʹ�� {

	public static void main(String[] args) {
		ArrayList<Student> stuList = new ArrayList<Student>(20);//����stuList�Ľ���������Student���趨Ĭ��������20��Ԫ�� 
		stuList.add(new Student("ciong", 21));
		stuList.add(new Student("xanarry", 11));
		stuList.add(new Student("amith", 21));
		stuList.add(new Student("jason", 19));
		stuList.add(new Student("marray", 25));
		stuList.add(new Student("blex", 21));//���6��ѧ����stuList��
		
		System.out.println("---original order---");
		
		for (Iterator<Student> iterator = stuList.iterator(); iterator.hasNext(); ) {//ʹ�õ�����������������ѧ����Ϣ
			System.out.println(iterator.next());
		}
		
		//ʹ��sort��������
		//д��1��
		stuList.sort(null);
		///д��2��
		Collections.sort(stuList);
		
		System.out.println("---sorted---");
		for (Iterator<Student> iterator = stuList.iterator(); iterator.hasNext(); ) {//����������
			System.out.println(iterator.next());
		}
	}
}