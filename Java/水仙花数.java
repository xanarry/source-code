import java.util.*;
public class Ë®ÏÉ»¨Êý {
	public static void main(String[] args) {
		for (int i = 100; i < 1000; i++) {
			if (isShuixianhua(i))
				System.out.println(i);
		}
	}

	static boolean isShuixianhua(int n) {
		int the_unit = n % 10;
		int decade = (n/10) % 10;
		int hundreds_place = n / 100;
		if (the_unit * the_unit * the_unit + decade * decade *decade + hundreds_place * hundreds_place * hundreds_place == n)
			return true;
		else
			return false;
	}
}