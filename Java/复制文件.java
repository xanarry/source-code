import java.util.*;
import java.io.*;

public class �����ļ� {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input source file path: ");
		String src = in.nextLine();
		
		System.out.print("input destination file path: ");
		String dest = in.nextLine();

		FileInputStream inFile = null;
		FileOutputStream outFile = null;
		try {
			inFile = new FileInputStream(new File(src));
		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
			System.exit(0);
		}

		try {
			outFile = new FileOutputStream(new File(dest), true);//FileOutputStream�ڶ�����������ȷ�������(true)��������д���ļ�
		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
			System.exit(0);
		}
			
		try {
			byte[] buffer = new byte[1024];
			int getLen = 0;
			long start = System.currentTimeMillis(); 
			while ((getLen = inFile.read(buffer)) != -1) {
				outFile.write(buffer, 0, getLen);
			}
			long end = System.currentTimeMillis(); 
			System.out.println("time consume: " + (end - start) + "ms");
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} finally {
			try {
				inFile.close();
				outFile.close();
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
		}
	}
}

/*
import java.io.File;  
import java.io.FileInputStream;  
import java.io.FileNotFoundException;  
import java.io.FileOutputStream;  
import java.io.IOException;  
import java.io.InputStream;  
import java.io.OutputStream;  
  
public class FileCopy {  
    private File inputFile;  
    private File outputFile;  
    private InputStream inputStream;  
    private OutputStream outputStream;  
    public FileCopy(String inputPath,String outputPath) throws FileNotFoundException{  
        inputFile=new File(inputPath);  
        outputFile=new File(outputPath);  
        inputStream=new FileInputStream(inputFile);  
        outputStream=new FileOutputStream(outputFile);  
          
    }  
    //һ���԰�����ȫ����ȡ���ڴ���������һ����д��  
    public void copy1() throws IOException{  
        byte b[]=new byte[(int)inputFile.length()];  
        inputStream.read(b);       //һ���Զ���  
        outputStream.write(b);   //һ����д��  
//      inputStream.close();  
//      outputStream.close();  
    }  
    //�߶���д  
    public void copy2() throws IOException{  
        int temp=0;  
        while((temp=inputStream.read())!=-1){  
            outputStream.write(temp);  
        }  
        inputStream.close();  
        outputStream.close();  
    }  
      
    public File getInputFile() {  
        return inputFile;  
    }  
    public void setInputFile(File inputFile) {  
        this.inputFile = inputFile;  
    }  
    public File getOutputFile() {  
        return outputFile;  
    }  
    public void setOutputFile(File outputFile) {  
        this.outputFile = outputFile;  
    }  
    public static void main(String[] args) throws IOException{  
        String inputPath="e:"+File.separator+"Xfire.rar";  
        String outputPath="f:"+File.separator+inputPath.substring(inputPath.indexOf(File.separator));  
        FileCopy fileCopy=new FileCopy(inputPath, outputPath);  
        long start1=System.currentTimeMillis();  
        fileCopy.copy1();  
        long end1=System.currentTimeMillis();  
        System.out.println("һ����ȫ�������ڴ渴���ļ���СΪ"+fileCopy.getInputFile().length()+"λ����ʱ��Ϊ:"+(end1-start1)+"ms");  
          
          
        fileCopy.getOutputFile().delete();  
        long start2=System.currentTimeMillis();  
        fileCopy.copy2();  
        long end2=System.currentTimeMillis();  
        System.out.println("�߶���д�����ļ���СΪ"+fileCopy.getInputFile().length()+"λ����ʱ��Ϊ:"+(end2-start2)+"ms");  
    }  
  
}  
*/