import java.util.*;
class person {
	String name;
	char sex;
	public person() {
		name = "null";
		sex = '0';
	}
	public person(String n, char s) {
		name = n;
		sex = s;
	}
	public void setName(String n) {
		name = n;
	}
	public void setSex(char s) {
		sex = s;
	}
	public String getName() {
		return name;
	}
	public char getSex() {
		return sex;
	}
	public void display() {
		System.out.println("name = " + name + " sex = " + sex);
	}
}

public class 对象继承 {
	public static void main(String[] args) {
		person p1 = new person("xiong", 'F');
		p1.display();

		person pl[] = new person[3];
		pl[0] = new person("zhang", 'F');
		pl[1] = new person("abc", 'M');
		pl[2] = new person("xyz", 'F');
		for (person t : pl) {
			t.display();
		}
	}
}
/*
---------------------------------------------
class my_class{
	自定义内容
}

public class fileName {
	public static void main(String[] args) {
		my_class use_it = new my_class();
	}
}
---------------------------------------------
public class fileName {
	public static void main(String[] args) {
		class my_class {
			自定义内容
		}

		my_class use_it = new my_class();
	}
}
---------------------------------------------
*/