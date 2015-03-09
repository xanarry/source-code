import java.text.DecimalFormat;
import java.util.ArrayList;

public class Calculate {
	public static String calculate(String expresion) {
		
		if (expresion.charAt(0) == '-') {
			expresion = "0" + expresion;
		}
		
		expresion = expresion.replaceAll("��", "/");
		
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
		
		//�����ʽ�еĳ˷����ʽ�������
		int start = 0; 
		int end = 0;

		for (int i = 0; i < expresion.length(); i++) {
			if ( (expresion.charAt(i) == '=') || (expresion.charAt(i) == '-' || expresion.charAt(i) == '+') && Character.isDigit(expresion.charAt(i - 1)) && Character.isDigit(expresion.charAt(i + 1)) ) {
				oper.add(expresion.charAt(i));//���������
				end = i;
				String temp = expresion.substring(start, end);
				if (!temp.contains("*") && !temp.contains("/")) {
					//���ǳ˷����ʽ����ArrayList
					nums.add(Double.parseDouble(temp));
				} else {
					//����Ǳ��ʽ����ú������㣬������һ���ַ�����ֵ
					String tNum = calMutiDevi(temp);
					nums.add(Double.parseDouble(tNum));
				}
				start = end + 1;
			} 
		}
		
		//ִ�мӷ�����
		double result = nums.get(0);
		for (int i = 0; i < oper.size() - 1; i++) {
			if (oper.get(i) == '+') {
				result += nums.get(i + 1);
			}
			if (oper.get(i) == '-') {
				result -= nums.get(i + 1);
			}
		}
		
		//�����������0����������ص�ֵ��Infinity���ж��Ƿ���һ��������ֵ
		if (String.valueOf(result) == "Infinity") {//�������
			return "��";
		} else if (String.valueOf(result) == "-Infinity") {//�������
			return "-��";
		} else {//�������
			return trim(result);
		}
	}
	
	public static String calMutiDevi(String t) {
		t += "=";
		
		ArrayList<Double> nums = new ArrayList<Double>();
		ArrayList<Character> oper = new ArrayList<Character>();
		
		//���������������
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

		//����˷�
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
		final int MAXLEN = 14;//�޶�����Ľ���ĳ���Ϊ14�����û��С�������14�������������5λС������ֻ�����9λ����
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
		df.setMaximumFractionDigits(getLen); // �������С��λ  
		trimResult = df.format(temp);
		
		//ȡ���Կ�ѧ���㷨������
		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < trimResult.length(); i++) {
			if (trimResult.charAt(i) != ',') {
				sb.append(trimResult.charAt(i));
			}
		}
		return sb.toString();
	}
}

/*��������
 * 123+45-123*53/2134 = 164.94517338331772
 * 64/2/2/2/2/2*4*4*4-8+7 = 127
 * 1+2+3+4+5+6+7+8+9+10 = 55
 * 10-1-2-3-4-5-6-7-8-9-10 = -45
 * 1*2*3*4*5*6*7 = 5040
 * 34-2*3+7-8/4/2+5 = 39
 * 34-2*3+7-8/4/2+5-27/3+5 = 35
 * 123+00-123*53/2134+23-0+12 = 154.9451733833177
 * 12/4/0+3 = ��
 */

