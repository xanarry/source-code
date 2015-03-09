public class 自定义异常 {
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
//自定义的异常类,因为要同时同public类和Tourist类访问，所以定义在外面/////////
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


/*单独在一个类中的写法
public class Tourist {
	public static void main(String[] args) {
		for (int i = 0; i < 100; i++) {
			try {
				new Tourist().takeTour();
			} catch (HotException e) {
				System.out.println(e.getMessage());
			} catch (ColdException e) {//抛出的是异常对象e
				System.out.println(e.getMessage());//调用异常对象e中的getMessage()函数输出错误信息，不要写成e.getMessage
			} finally {
				System.out.println("just fine here!!!");
			}
		}
	}

	public void takeTour() throws HotException, ColdException {
		int temperature = (int)(Math.random() * 100 - 30);
		if (temperature > 40)
			throw new HotException(temperature + "C is too hot!");//抛出异常实质上是抛出一个异常对象向，所以要用new关键词
		else if (temperature < -10) 
			throw new ColdException(temperature + "C so cold here!");
	}
///////自定义的异常类(可以在Tourist类中,也可以在外面/////////
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
/////////////////自定义的异常类//////////////////////////////
}
*/