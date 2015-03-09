import java.util.*;
import java.lang.*;

public class 大小写字母转换 {
	public static void main(String[] args) throws Exception {
		System.out.print("input a letter:");
		char output, input = (char)System.in.read();

		if (Character.isUpperCase(input))//Charater类, 类似于c/c++ ctype的一个东西，必须是Character.isUpperCase(),不能isUpperCase()
			output = (char)(input + 32);
		else if (Character.isLowerCase(input))
			output = (char)(input - 32);
		else output = input;

		System.out.println(output);
	}
}