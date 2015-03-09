class person {
	private String name;
	public person(String n) {
		name = n;
	}
	public String getName() {
		return name;
	}
	public void bellReaction() {
		System.out.println("no bellReaction");	
	}
}

class student extends person {
	public student(String n) {
		super(n);
	}
	public void bellReaction() {
		System.out.println("return to classroom and listen");
	}
}

class teacher extends person {
	public teacher(String n) {
		super(n);
	}
	public void bellReaction() {
		System.out.println("goto classroom and instruction");
	}
}
public class ∂‡Ã¨ {
	public static void main(String[] args) {
		person p = new person("person");
		System.out.println(p.getName());
		p.bellReaction();

		student s = new student("student");
		System.out.println(s.getName());
		s.bellReaction();

		teacher t = new teacher("teacher");
		System.out.println(t.getName());
		t.bellReaction();
	}
}