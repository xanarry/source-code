import java.util.Comparator;
import java.util.Iterator;
import java.util.SortedSet;
import java.util.TreeSet;

class Person implements Comparable<Person> {
	private String name;
	private int age;

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public Person(String name, int age) {
		super();
		this.name = name;
		this.age = age;
	}

	@Override
	public int compareTo(Person other) {
		return this.age - other.age;
	}

	@Override
	public String toString() {
		return "Person [name=" + name + ", age=" + age + "]";
	}

}
//ʹ��treeSetʱ��ϵͳ�ṹ��һ������������������������򣬱������ܵõ��������Ϣ�б�������� ��
public class ������_���� {

	public static void main(String[] args) {
		SortedSet<Person> personSeta = new TreeSet<Person>();
		personSeta.add(new Person("xiong", 20));
		personSeta.add(new Person("zhu", 19));
		personSeta.add(new Person("zhang", 22));
		personSeta.add(new Person("yang", 21));
		personSeta.add(new Person("wang", 24));
		personSeta.add(new Person("cheng", 23));
		
		System.out.println("default sorted by age");
		Iterator<Person> iterator = personSeta.iterator();
		while (iterator.hasNext()) {
			System.out.println(iterator.next());
		}
		
		//ע�⹹�캯��������������������ݵ��Ǹ�treeSet���������
		SortedSet<Person> personSetb = new TreeSet<Person>(new Comparator<Person>() {

			@Override
			public int compare(Person a, Person b) {
				return a.getName().compareTo(b.getName());
			}
			
		});
		personSetb.addAll(personSeta);//addAllֱ�Ӹ�������һ����set
		
		System.out.println("\nsorted set by name");
		Iterator<Person> iterator2 = personSetb.iterator();
		while (iterator2.hasNext()) {
			System.out.println(iterator2.next());
		}
	}

}
