class superClass {
	public superClass() {
		System.out.println("Create superClass");
	}
	public superClass(String s) {
		System.out.println("Create superClass with " + s);
	}
}

public class childClass extends superClass {
	public childClass() {
		super();
		System.out.println("Create childClass");
	}
	public childClass(String s) {
		super(s);
		System.out.println("Create childClass with " + s);
	}

	public static void main(String[] args) {
		childClass c = new childClass();
		childClass sc = new childClass("test");
	}
}