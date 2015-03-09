import java.util.*;

class Computer {//外部类
	private String tradeMark;
	private Memory memory;
	private HardDisk hdd;

	public Computer(String tm) {
		this.tradeMark = tm;
	}

	public class Memory {//内部类1
		private int frequency;
		private int size;

		public Memory(int f, int s) {
			this.frequency = f;
			this.size = s;
			memory = this;//内部类和外部类的互访特性
		}

		public String toString() {
			return "frequency: " + this.frequency + "Hz size: " + this.size + "Gb\n";
		}
	}

	public class HardDisk {//内部类2
		private int cache;
		private int size;
		private int rpm;

		public HardDisk(int c, int s, int r) {
			this.cache = c;
			this.size = s;
			this.rpm = r;
			hdd = this;//内部类和外部类的互访特性
		}

		public String toString() {
			return "cache: " + this.cache + "Mb size: " + this.size + "Mb rpm: " + this.rpm +"rpm\n"; 
		}
	}

	public String toString() {
		StringBuffer sb = new StringBuffer("Computer information: \n");
		sb.append("tradeMark: " + this.tradeMark + "\n");
		if (this.memory != null)
			sb.append("memory: " + this.memory);
		if (this.hdd != null)
			sb.append("hdd: " + this.hdd);
		return sb.toString();
	}
}


class Raid extends Computer.HardDisk {//定义内部类的子类
	public static final int MAX_COUNT = 10;
	private int installHdd = 0;

	public Raid(Computer co, int count, int c, int s, int r) {
		co.super(c, s, r);//使用super构造函数是应该传递所在外部类的对象，这里传入的是computer

		if (this.installHdd+count < MAX_COUNT) {
			this.installHdd += count;
		}
		else {
			System.out.println("error! hdd socket is not enough for your request");
		}
	}

	public String toString() {
		return "count: " + installHdd + "\n" + super.toString();//普通调用不需要再加co.super
	}
}

public class 内部类的子类 {
	public static void main(String[] args) {
		Computer dell = new Computer("dell");
		Computer.HardDisk hdd1 = dell.new HardDisk(32, 500, 7200);
		Computer.Memory mem = dell.new Memory(1600, 4);
		System.out.println(dell);

		Raid raid = new Raid(dell, 2, 32, 500, 7200);
		System.out.println(raid);
		Raid raid1 = new Raid(dell, 10, 32, 500, 7200);
		System.out.println(raid1);
	}
}