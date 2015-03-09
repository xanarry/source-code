public class �Զ����쳣 {
	public static void main(String[] args) {
		Tourist t = null;
		for (int i = 0; i < 10000; i++) {
			try {
				new Tourist().takeTour();
			} catch (HotException he) {
				System.out.println(he.getMessage());
				continue;
			} catch (ColdException ce) {
				System.out.println(ce.getMessage());
				continue;
			} finally {
				System.out.println("      fine here, haha");
			}
		}
	}
}

class Tourist {
	public void takeTour() throws HotException, ColdException {
		int temperature = (int)(Math.random() * 100 - 30);
		if (temperature >= 40)
			throw new HotException(temperature + "C   is too hot!");
		else if (temperature <= -10)
			throw new ColdException(temperature + "C  here is too cold!");
	}
}
//�Զ�����쳣��,��ΪҪͬʱͬpublic���Tourist����ʣ����Զ���������/////////
class HotException extends Exception {
	public HotException(String msg) {
		super(msg);
	}
}

class ColdException extends Exception {
	public ColdException(String msg) {
		super(msg);
	}
}


/*������һ�����е�д��
public class Tourist {
	public static void main(String[] args) {
		for (int i = 0; i < 100; i++) {
			try {
				new Tourist().takeTour();
			} catch (HotException e) {
				System.out.println(e.getMessage());
			} catch (ColdException e) {//�׳������쳣����e
				System.out.println(e.getMessage());//�����쳣����e�е�getMessage()�������������Ϣ����Ҫд��e.getMessage
			} finally {
				System.out.println("just fine here!!!");
			}
		}
	}

	public void takeTour() throws HotException, ColdException {
		int temperature = (int)(Math.random() * 100 - 30);
		if (temperature > 40)
			throw new HotException(temperature + "C is too hot!");//�׳��쳣ʵ�������׳�һ���쳣����������Ҫ��new�ؼ���
		else if (temperature < -10) 
			throw new ColdException(temperature + "C so cold here!");
	}
///////�Զ�����쳣��(������Tourist����,Ҳ����������/////////
	class HotException extends Exception {
		public HotException(String msg) {
			super(msg);
		}
	}

	class ColdException extends Exception {
		public ColdException(String msg) {
			super(msg);
		}
	}
/////////////////�Զ�����쳣��//////////////////////////////
}
*/