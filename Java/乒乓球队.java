public class ƹ����� {
	public static void main(String[] args) {
		//�����ĵ��Ҷӵ�
		for (char i = 'x'; i <= 'z'; i++) {//��ʾ�׶ӵ�A������xyz����
			for (char j = 'x'; j <= 'z'; j++) {//��ʾ�׶ӵ�B������xyz����
				for (char k = 'x'; k <= 'z'; k++) {//��ʾ�׶ӵ�C������xyz����
					if (i != j && j != k && k != i) {//�ų�������ͬ�¾���һ����
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