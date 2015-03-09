import java.text.DecimalFormat;
import java.util.ArrayList;

public class Calculate {
	public static String calculate(String expresion) {
		
		if (expresion.charAt(0) == '-') {
			expresion = "0" + expresion;
		}
		
		expresion = expresion.replaceAll("÷", "/");
		
		switch (expresion.charAt(expresion.length() - 1)) {
		case '+':
		case '-':
			expresion += "0=";
			break;
			
		case '/':
		case '*':
			expresion += "1=";
			break;
			
		default:
			expresion += "=";
			break;
		}
		
		ArrayList<Double> nums = new ArrayList<Double>();
		ArrayList<Character> oper = new ArrayList<Character>();
		
		//将表达式中的乘法表达式分离出来
		int start = 0; 
		int end = 0;

		for (int i = 0; i < expresion.length(); i++) {
			if ( (expresion.charAt(i) == '=') || (expresion.charAt(i) == '-' || expresion.charAt(i) == '+') && Character.isDigit(expresion.charAt(i - 1)) && Character.isDigit(expresion.charAt(i + 1)) ) {
				oper.add(expresion.charAt(i));//保存运算符
				end = i;
				String temp = expresion.substring(start, end);
				if (!temp.contains("*") && !temp.contains("/")) {
					//将非乘法表达式放入ArrayList
					nums.add(Double.parseDouble(temp));
				} else {
					//如果是表达式则调用函数计算，并返回一个字符串的值
					String tNum = calMutiDevi(temp);
					nums.add(Double.parseDouble(tNum));
				}
				start = end + 1;
			} 
		}
		
		//执行加法运算
		double result = nums.get(0);
		for (int i = 0; i < oper.size() - 1; i++) {
			if (oper.get(i) == '+') {
				result += nums.get(i + 1);
			}
			if (oper.get(i) == '-') {
				result -= nums.get(i + 1);
			}
		}
		
		//如果遇到除以0的情况，返回的值是Infinity，判断是否是一个正常的值
		if (String.valueOf(result) == "Infinity") {//正无穷大
			return "∞";
		} else if (String.valueOf(result) == "-Infinity") {//负无穷大
			return "-∞";
		} else {//正常结果
			return trim(result);
		}
	}
	
	public static String calMutiDevi(String t) {
		t += "=";
		
		ArrayList<Double> nums = new ArrayList<Double>();
		ArrayList<Character> oper = new ArrayList<Character>();
		
		//分离数字与运算符
		int start = 0;
		int end = 0;
		for (int i = 0; i < t.length(); i++) {
			if (t.charAt(i) == '*' || t.charAt(i) == '/' || t.charAt(i) == '=') {
				end = i;
				nums.add(Double.parseDouble(t.substring(start, end)));
				oper.add(t.charAt(i));
				start = end + 1;
			} 
		}

		//计算乘法
		Double dResult = nums.get(0);
		for (int i = 0; i < oper.size() - 1; i++) {
			if (oper.get(i) == '*') {
				dResult *= nums.get(i + 1);
			}
			if (oper.get(i) == '/') {
				dResult /= nums.get(i + 1);
			}
		}
		return dResult.toString();
	}
	
	public static String trim(Double temp) {
		final int MAXLEN = 14;//限定输出的结果的长度为14，如果没有小数就输出14个整数，如果有5位小数，就只能输出9位整数
		String trimResult = String.valueOf(temp);
		DecimalFormat df = new DecimalFormat();  

		int pointLocation = 0;
		for (int i = 0; i < trimResult.length(); i++) {
			if (trimResult.charAt(i) == '.') {
				pointLocation = i;
				break;
			}
		}
		int getLen = MAXLEN - pointLocation - 1;
		df = new DecimalFormat();  
		df.setMaximumFractionDigits(getLen); // 设置最大小数位  
		trimResult = df.format(temp);
		
		//取消以科学计算法输出结果
		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < trimResult.length(); i++) {
			if (trimResult.charAt(i) != ',') {
				sb.append(trimResult.charAt(i));
			}
		}
		return sb.toString();
	}
}

/*测试数据
 * 123+45-123*53/2134 = 164.94517338331772
 * 64/2/2/2/2/2*4*4*4-8+7 = 127
 * 1+2+3+4+5+6+7+8+9+10 = 55
 * 10-1-2-3-4-5-6-7-8-9-10 = -45
 * 1*2*3*4*5*6*7 = 5040
 * 34-2*3+7-8/4/2+5 = 39
 * 34-2*3+7-8/4/2+5-27/3+5 = 35
 * 123+00-123*53/2134+23-0+12 = 154.9451733833177
 * 12/4/0+3 = ∞
 */

