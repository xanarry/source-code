import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.io.Serializable;


public class 读写对象 {

	public static void main(String[] args) {
		Person p1 = new Person("xiongyagn", 'F', 21);
		Person p2 = new Person("jason mraz", 'F', 33);
		
		OutputStream outputStream = null;
		ObjectOutputStream objectOutputStream = null;
		FileInputStream inputStream = null;
		ObjectInputStream objectInputStream = null;
		
		//写入对象到文件
		try {
			outputStream = new FileOutputStream("1111.txt");
			objectOutputStream = new ObjectOutputStream(outputStream);
			
			objectOutputStream.writeObject(p1);
			objectOutputStream.writeObject(p2);
			objectOutputStream.writeObject(new Integer(1000));
			
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} finally {
			try {
				outputStream.close();
				objectOutputStream.close();
			} catch (IOException e) {
				e.getStackTrace();
			}
		}
		
		//读取文件已对象形式
		try {
			inputStream = new FileInputStream("1111.txt");
			objectInputStream = new ObjectInputStream(inputStream);
			
			Person pp1 = (Person) objectInputStream.readObject();
			pp1.display();
			Person pp2 = (Person) objectInputStream.readObject();
			pp2.display();
			Integer i = (Integer) objectInputStream.readObject();
			System.out.println(i);
		} catch (Exception e) {
			System.out.println(e.getMessage());
		} finally {
			try {
				inputStream.close();
				objectInputStream.close();
			} catch (IOException e) {
				e.getStackTrace();
			}
		}
	}

}

class Person implements Serializable {
	private static final long serialVersionUID = 1L;
	private String name;
	private char sex;
	private int age;
	
	public Person(){}
	public Person(String n, char s, int a) {
		name = n;
		sex = s;
		age = a;
	}
	public void display() {
		System.out.println("name = " + name);
		System.out.println("sex = " + sex);
		System.out.println("age = " + age);
	}
	public String toString() {
		return "Person [name=" + name + ", sex=" + sex + ", age=" + age + "]";
	}
}