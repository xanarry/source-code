public class Computer {
	public  static final int MAX_DRIVER = 4;
	private int installDrives = 0;
	private HardDrive[]  drives= new HardDrive[MAX_DRIVER];//储存内部类对象的数组
	private int memSize;

	public Computer(int memSize) {
		this.memSize = memSize;
	}

	public String toString() {
		StringBuffer sb = new StringBuffer("Memory: " + memSize + "MB");//使用StringBuffer对象
		for (int i = 0; i < installDrives; i++) {
			sb.append(", Drive" + i + ": ");
			sb.append(drives[i].size + "MB");
		}

		return sb.toString();
	}

	public class HardDrive {
		private int size;

		public HardDrive(int size) throws Exception {
			this.size = size;

			if (installDrives < MAX_DRIVER) {
				drives[installDrives++] = this;//将自身对象添加到外部类中的数组中
			} else {
				throw new Exception("no more Memory");
			}
		}
	}

 	public static void main(String[] args) throws Exception {
		Computer atWork = new Computer(64);
		System.out.println(atWork);

		HardDrive IDE1 = atWork.new HardDrive(1024);//每执行一次则会在数组中添加一个属于内部类实例化的对象
		HardDrive IDE2 = atWork.new HardDrive(2048);
		HardDrive IDE3 = atWork.new HardDrive(4096);
		System.out.println(atWork);
	}
}