interface Sortble { //定义排序函数的接口
    public int Compare(Sortble s);//接口包含比较函数
}

class Student implements Sortble { //学生类
	private String name;
    private int score;

    Student(String n, int s) {
    	name = n;
        score = s;
    }

    public int Compare(Sortble s) { //在类中实现接口函数
        // TODO Auto-generated method stub
        Student ss = null;
        if(s instanceof Student) {//如果s是student的的对象
            ss = (Student)s;//类型转换
        }
        else {
            System.out.println("程序出错，意外退出");
            System.exit(0);
        }

        if(this.getScore() > ss.getScore()) 
            return 1;
        else if(this.getScore() < ss.getScore())
            return -1;
        else
            return 0;
    }

    public String toString() {
        return "name: " + getName() + "  score = " + getScore();
    }

    public void setScore(int score) {
        this.score = score;
    }

    public int getScore() {
        return score;
    }

    public void setName(String n) {
    	name = n;
    }

    public String getName() {
    	return name;
    }
}

class Rectangle implements Sortble//矩形类
{
	private String name;
    private int length, width;

    Rectangle(String n, int length, int width) {
    	this.name = n;
        this.length = length;
        this.width = width;
    }

    public int area() {
        return length * width;
    }

    public int getLength() {
        return length;
    }

    public void setLength(int length) {
        this.length = length;
    }

    public int getWidth() {
        return width;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public int Compare(Sortble s) {
        Rectangle ss = null;
        // TODO Auto-generated method stub
        if(s instanceof Rectangle) {
            ss = (Rectangle)s;
        }
        else {
            System.out.println("程序出错，意外退出");
            System.exit(0);
        }

        if(this.area() > ss.area())
            return 1;
        else if(this.area() < ss.area())
            return -1;
        else
            return 0;
    }

    public String toString() {
        return name + ": area = " + area();
    }
}

class Sort {
    public static void SelectSort(Sortble[] a) {
        Sortble m = null;
        for(int i = 0; i < a.length - 1; i++) { //升序
            for(int j = i + 1; j < a.length; j++) {
                if(a[j].Compare(a[i]) < 0) {
                    m = a[i];
                    a[i] = a[j];
                    a[j] = m;
                }
            }
        }
    }
}

public class x接口 {
    public x接口() {
        Student[] s = new Student[5];
        for(int i = 0; i < s.length; i++) {
            s[i] = new Student("Student" + String.valueOf(i + 1), (int)(Math.random() * 100));
        }

        Sort.SelectSort(s);
        System.out.println("下面是按升序输出学生成绩");
        for(int i = 0; i < s.length; i++) {
            System.out.println(s[i]);
        }

        Rectangle[] ss = new Rectangle[5];
        for(int i = 0; i < ss.length; i++) {
            ss[i] = new Rectangle("Rectangle" + String.valueOf(i + 1), (int)(Math.random() * 100), (int)(Math.random() * 100));
        }

        Sort.SelectSort(ss);
        System.out.println("下面是按升序输出矩形面积");
        for(int i = 0; i < ss.length; i++) {
            System.out.println(ss[i]);
        }
    }

    public static void main(String[] arg) {
        new x接口();
    }
}