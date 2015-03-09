class outerClass {
	private int count = 100;

	public int getCount() {
		return count;
	}

	public class innerClass {
		private int count = 10;//使用与外部类同名的变量

		public void outadd() {
			outerClass.this.count++;//操作外部类的同名变量
		}

		public void inadd() {//操作内部类的同名变量
			count++;
		}

		public int getCount() {//输入内部类的变量值
			return count;
		}
	}
}

public class 内部类访问外部类变量 {
	public static void main(String[] args) {
		outerClass outc = new outerClass();//实例化外部类
		System.out.println(outc.getCount());

		outerClass.innerClass inc = outc.new innerClass();//实例化内部类，注意前面都是类名，后面是实例化对象的名字
		System.out.println(inc.getCount());

		inc.inadd();//内部类对自身变量自加
		System.out.println(inc.getCount());

		inc.outadd();//内部类对外部类变量自加
		System.out.println(outc.getCount());
	}
}