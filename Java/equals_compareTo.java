public class equals_compareTo {
	public static void main(String[] args) {
		String a = "abcd";
		String b = "abcd";

		String c = new String("abcd");
		String d = new String("abcd");

		String e = c;
		String f = "absd";

		System.out.println("a.equals(b): " + a.equals(b));//a和b在字面上的每个字母都是相同的，所以返回TRUE
		System.out.println("b.equals(c): " + b.equals(c));//c和b在字面上的每个字母都是相同的，所以返回TRUE

		System.out.println("a == b: " + (a == b));//此处为什么会返回TRUE呢，原因是我们先定义了a="abcd",当我们再次定义b="abcd"是，系统检测到已经在内存中存在了相同的"abcd",所以b会直接引用已有的"abcd"

		System.out.println("a == c: " + (a == c));//a和c不是引用的同一个对象，所以false
		System.out.println("a == f: " + (c == d));//d和c不是引用的同一个对象，所以false

		System.out.println("c == e: " + (c == e));//e引用c,所以比较会返回true

		System.out.println("f.compareTo(c): " + f.compareTo(c));//比价结果是16,即s与c的anscII码差值
		System.out.println("a.compareTo(c): " + a.compareTo(c));//ac值相同,返回0
	}
}