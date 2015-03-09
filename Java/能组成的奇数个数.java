public class 能组成的奇数个数 {
	public static void main(String[] args) {
		int count = 0;
		for (int l1 = 0; l1 <= 7; l1++) {
			for (int l2 = 0; l2 <= 7; l2++) {
				for (int l3 = 0; l3 <= 7; l3++) {
					for (int l4 = 0; l4 <= 7; l4++) {
						for (int l5 = 0; l5 <= 7; l5++) {
							for (int l6 = 0; l6 <= 7; l6++) {
								for (int l7 = 0; l7 <= 7; l7++) {
									if (l1 != 0 && l1 != l2 && l2 != l3 && l3 != l4 && l4 != l5 && l5 != l6 && l6 != l7) {
										if ((l1 * 1000000 + l2 * 100000 + l3 * 10000 + l4 * 1000 + l5 * 100 + l6 * 10 + l7) % 2 == 0) {
											count++;
										}
									}	
								}
							}
						}
					}
				}
			}
		}
		System.out.println(count);
	}
}