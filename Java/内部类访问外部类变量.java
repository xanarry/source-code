class outerClass {
	private int count = 100;

	public int getCount() {
		return count;
	}

	public class innerClass {
		private int count = 10;//ʹ�����ⲿ��ͬ���ı���

		public void outadd() {
			outerClass.this.count++;//�����ⲿ���ͬ������
		}

		public void inadd() {//�����ڲ����ͬ������
			count++;
		}

		public int getCount() {//�����ڲ���ı���ֵ
			return count;
		}
	}
}

public class �ڲ�������ⲿ����� {
	public static void main(String[] args) {
		outerClass outc = new outerClass();//ʵ�����ⲿ��
		System.out.println(outc.getCount());

		outerClass.innerClass inc = outc.new innerClass();//ʵ�����ڲ��࣬ע��ǰ�涼��������������ʵ�������������
		System.out.println(inc.getCount());

		inc.inadd();//�ڲ������������Լ�
		System.out.println(inc.getCount());

		inc.outadd();//�ڲ�����ⲿ������Լ�
		System.out.println(outc.getCount());
	}
}