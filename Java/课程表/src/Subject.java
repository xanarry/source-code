import java.util.ArrayList;

public class Subject implements Comparable<Subject> {
	String name;
	String location;
	int classTime;
	ArrayList<Integer> weekRange;

	public Subject(String name, String location, int classTime,
			ArrayList<Integer> weekRange) {
		super();
		this.name = name;
		this.location = location;
		this.classTime = classTime;
		this.weekRange = weekRange;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getLocation() {
		return location;
	}

	public void setLocation(String location) {
		this.location = location;
	}

	public int getClassTime() {
		return classTime;
	}

	public void setClassTime(int classTime) {
		this.classTime = classTime;
	}

	public ArrayList<Integer> getWeekRange() {
		return weekRange;
	}

	public void setWeekRange(ArrayList<Integer> weekRange) {
		this.weekRange = weekRange;
	}

	public String toString() {
		return "Subject [name=" + name + ", location=" + location
				+ ", classTime=" + classTime + ", weekRange=" + weekRange + "]";
	}

	public int compareTo(Subject o) {
		return this.classTime - ((Subject)o).getClassTime();
	}

}
