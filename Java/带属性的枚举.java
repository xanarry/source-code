public class 带属性的枚举 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("laptop price list");
		for (Laptop laptop : Laptop.values()) {
			System.out.println(laptop + "  " + laptop.getPrice());
		}
		System.out.println();
	}

}

enum Laptop {
	ThinkPad(100), Dell(200), Lenovo(300), Asus(400), Hp(500);
	private int price;
	
	private Laptop(int price) {
		// TODO Auto-generated constructor stub
		this.price = price;
	}
	
	public int getPrice() {
		return price;
	}
}
