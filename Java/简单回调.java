import java.util.*;

class Caller  {  //��Ҫ���õ���
    public MyCallInterface mc;  //�����ӿ�
  
    public void setCallfuc(MyCallInterface mc) {  
       this.mc = mc;  
    }  
  
    public void call() {  
       this.mc.method();  
    }  
}  

interface MyCallInterface {  //���屻���ú����Ľӿ�
    public void method();  
}  

public class �򵥻ص� implements MyCallInterface {  //���屻���õ���
    public void method() {  
       System.out.println("�ص�");  
    }  
  
    public static void main(String args[]) {  
       Caller call = new Caller();  //ʵ��caller
       call.setCallfuc(new �򵥻ص�());  //�������õ��ഫ�ݸ�caller
       call.call();  //�ص�����
    }  
}  