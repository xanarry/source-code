public class SynchronizedThread { 
    public static void main(String[] args) { 
        User u = new User("��ĳ", 100); 
        MyThread2 t1 = new MyThread2("�߳�A", u, -10); 
        MyThread2 t2 = new MyThread2("�߳�B", u, -50); 
        MyThread2 t3 = new MyThread2("�߳�C", u, -60); 
        MyThread2 t4 = new MyThread2("�߳�D", u, -40); 
        MyThread2 t5 = new MyThread2("�߳�E", u, 20); 
        MyThread2 t6 = new MyThread2("�߳�F", u, 28); 

        t1.start(); 
        t2.start(); 
        t3.start(); 
        t4.start(); 
        t5.start(); 
        t6.start(); 
    } 
} 

////////////////////////////////////////////////
class MyThread2 extends Thread { 
    private User u; 
    private int y = 0; 

    MyThread2(String name, User u, int y) { 
        super(name); 
        this.u = u; 
        this.y = y; 
    } 

    public void run() { 
        u.oper(y); 
    } 
} 
////////////////////////////////////////////////

class User { 
    private String code; 
    private int cash; 

    User(String code, int cash) { 
        this.code = code; 
        this.cash = cash; 
    } 

    public String getCode() { 
        return code; 
    } 

    public void setCode(String code) { 
        this.code = code; 
    } 

    public synchronized void oper(int x) { 
        try { 
            Thread.sleep(10L); 
            this.cash += x; 
            System.out.println(Thread.currentThread().getName() + "���н��������� " + x + "����ǰ�˻����Ϊ" + cash); 
            Thread.sleep(10L); 
        } catch (InterruptedException e) { 
            e.printStackTrace(); 
        } 
    } 

    @Override 
    public String toString() { 
        return "User{" + "code='" + code + '\'' + ", cash=" + cash + '}'; 
    } 
}