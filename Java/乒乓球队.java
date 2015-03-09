public class 乒乓球队 {
	public static void main(String[] args) {
		//遍历的的乙队的
		for (char i = 'x'; i <= 'z'; i++) {//表示甲队的A可以与xyz比赛
			for (char j = 'x'; j <= 'z'; j++) {//表示甲队的B可以与xyz比赛
				for (char k = 'x'; k <= 'z'; k++) {//表示甲队的C可以与xyz比赛
					if (i != j && j != k && k != i) {//排除两个人同事竞赛一个人
						if (i != 'x' && k != 'x' && k != 'z') {
							System.out.println("A -> " + i);
							System.out.println("B -> " + j);
							System.out.println("C -> " + k);
						}
					}
				}
			}
		}
	}
}