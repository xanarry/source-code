package a.a;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class AActivity extends Activity
{
    /** Called when the activity is first created. */

    EditText Ev1;

    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        Ev1 = (EditText)findViewById(R.id.editText1);

        //��һ�ַ�ʽ
        Button Btn1 = (Button)findViewById(R.id.button1);//��ȡ��ť��Դ
        Btn1.setOnClickListener(new Button.OnClickListener() //��������
        {
            public void onClick(View v)
            {
                String strTmp = "���Button01";
                Ev1.setText(strTmp);
            }

        });

        //�ڶ��ַ�ʽ
        Button Btn2 = (Button) findViewById(R.id.button2);//��ȡ��ť��Դ
        Btn2.setOnClickListener(listener);//���ü���

    }

    Button.OnClickListener listener = new Button.OnClickListener() //������������
    {
        public void onClick(View v)
        {
            String strTmp = "���Button02";
            Ev1.setText(strTmp);
        }

    };


    //�����ַ�ʽ(Android1.6�汾���Ժ�İ汾���ṩ��)
    public void Btn3OnClick(View view)
    {
        String strTmp = "���Button03";
        Ev1.setText(strTmp);

    }
}