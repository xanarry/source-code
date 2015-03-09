public class initialization_block {
	public static void main(String[] args) {
		person[] p = new person[4];
		p[0] = new person(100);
		p[1] = new person("xiong");
		p[2] = new person("zhong", 100);
		p[3] = new person();

		for (person t : p) {
			System.out.println("Id = " + t.getId() + ", name = " + t.getName() + ", score = " + t.getScore());
		}
	}
}

class person {
	private int id;
	private String name;
	private int score;

	static int nextId = 1;

	////////////////初始化块
	{
		id = nextId;
		nextId++;
	}
	/////////////////
	public person() {
		name = "default name";
		score = 60;
	}
	public person(int s) {
		name = "default name";
		score = s;
	}
	public person(String n) {
		name = n;
		score = 60;
	}
	public person(String n, int s) {
		name = n;
		score = s;
	}

	public String getName() {
		return name;
	}
	public int getId() {
		return id;
	}
	public int getScore() {
		return score;
	}
}