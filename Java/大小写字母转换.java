import java.util.*;
import java.lang.*;

public class ��Сд��ĸת�� {
	public static void main(String[] args) throws Exception {
		System.out.print("input a letter:");
		char output, input = (char)System.in.read();

		if (Character.isUpperCase(input))//Charater��, ������c/c++ ctype��һ��������������Character.isUpperCase(),����isUpperCase()
			output = (char)(input + 32);
		else if (Character.isLowerCase(input))
			output = (char)(input - 32);
		else output = input;

		System.out.println(output);
	}
}