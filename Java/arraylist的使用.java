import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;

class Student implements Comparable<Student> {//因为在ArrayList中使用了泛型，所以要在此用<>表明类型，比如是对String类实现的接口就写String  
    String name;  
    int age;  
  
    public Student(String name, int age) {  
        super();  
        this.name = name;  
        this.age = age;  
    }  
      
    public int compareTo(Student tempStudent) {//从写接口中的函数  
    	if (this.age != tempStudent.age) {//当年龄不相同时，则只按年龄的大小对学生进行排序  
        	return this.age - tempStudent.age;//交换两者的顺序可以实现是升序还是降序  
    	}  
    	else {//如果两个学生的年龄相同，那么我们就按其姓名排序  
        	if (!this.getName().equals(tempStudent.getName())) {//如果前几个字母都一样，我们就不能进行比较，所以要对第一个不同的字母进行比较  
            	int i = 0;  
            	while (i < this.name.length() && i < tempStudent.getName().length()) {//使用循序找到第一个不同的字母  
                	if (this.name.charAt(i) != tempStudent.getName().charAt(i))  
                	    break;  
                	i++;  
            	}  
            	return this.name.charAt(i) - tempStudent.getName().charAt(i);//返回名字的比较值  
       		}  
        	else//当名字相同是  
            	return -1;//顺便返回一个值，因为这不会影响排序的结果，只是为了与前面的if搭配  
    	}
    }  
  
	public String toString() {
		return "name=" + name + ", age=" + age;
	}
	
	public String getName() {
		return this.name;
	}
}

public class arraylist的使用 {

	public static void main(String[] args) {
		ArrayList<Student> stuList = new ArrayList<Student>(20);//设置stuList的接受类型是Student，设定默认容量是20个元素 
		stuList.add(new Student("ciong", 21));
		stuList.add(new Student("xanarry", 11));
		stuList.add(new Student("amith", 21));
		stuList.add(new Student("jason", 19));
		stuList.add(new Student("marray", 25));
		stuList.add(new Student("blex", 21));//添加6个学生到stuList中
		
		System.out.println("---original order---");
		
		for (Iterator<Student> iterator = stuList.iterator(); iterator.hasNext(); ) {//使用迭代器遍历输入所有学生信息
			System.out.println(iterator.next());
		}
		
		//使用sort函数排序
		//写法1：
		stuList.sort(null);
		///写法2：
		Collections.sort(stuList);
		
		System.out.println("---sorted---");
		for (Iterator<Student> iterator = stuList.iterator(); iterator.hasNext(); ) {//输入有序结果
			System.out.println(iterator.next());
		}
	}
}