import java.util.*;

class Caller  {  //需要调用的类
    public MyCallInterface mc;  //声明接口
  
    public void setCallfuc(MyCallInterface mc) {  
       this.mc = mc;  
    }  
  
    public void call() {  
       this.mc.method();  
    }  
}  

interface MyCallInterface {  //定义被调用函数的接口
    public void method();  
}  

public class 简单回调 implements MyCallInterface {  //定义被调用的类
    public void method() {  
       System.out.println("回调");  
    }  
  
    public static void main(String args[]) {  
       Caller call = new Caller();  //实例caller
       call.setCallfuc(new 简单回调());  //将被调用的类传递给caller
       call.call();  //回调函数
    }  
}  