public class equals_compareTo {
	public static void main(String[] args) {
		String a = "abcd";
		String b = "abcd";

		String c = new String("abcd");
		String d = new String("abcd");

		String e = c;
		String f = "absd";

		System.out.println("a.equals(b): " + a.equals(b));//a��b�������ϵ�ÿ����ĸ������ͬ�ģ����Է���TRUE
		System.out.println("b.equals(c): " + b.equals(c));//c��b�������ϵ�ÿ����ĸ������ͬ�ģ����Է���TRUE

		System.out.println("a == b: " + (a == b));//�˴�Ϊʲô�᷵��TRUE�أ�ԭ���������ȶ�����a="abcd",�������ٴζ���b="abcd"�ǣ�ϵͳ��⵽�Ѿ����ڴ��д�������ͬ��"abcd",����b��ֱ���������е�"abcd"

		System.out.println("a == c: " + (a == c));//a��c�������õ�ͬһ����������false
		System.out.println("a == f: " + (c == d));//d��c�������õ�ͬһ����������false

		System.out.println("c == e: " + (c == e));//e����c,���ԱȽϻ᷵��true

		System.out.println("f.compareTo(c): " + f.compareTo(c));//�ȼ۽����16,��s��c��anscII���ֵ
		System.out.println("a.compareTo(c): " + a.compareTo(c));//acֵ��ͬ,����0
	}
}