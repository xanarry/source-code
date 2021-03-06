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

        //第一种方式
        Button Btn1 = (Button)findViewById(R.id.button1);//获取按钮资源
        Btn1.setOnClickListener(new Button.OnClickListener() //创建监听
        {
            public void onClick(View v)
            {
                String strTmp = "点击Button01";
                Ev1.setText(strTmp);
            }

        });

        //第二种方式
        Button Btn2 = (Button) findViewById(R.id.button2);//获取按钮资源
        Btn2.setOnClickListener(listener);//设置监听

    }

    Button.OnClickListener listener = new Button.OnClickListener() //创建监听对象
    {
        public void onClick(View v)
        {
            String strTmp = "点击Button02";
            Ev1.setText(strTmp);
        }

    };


    //第三种方式(Android1.6版本及以后的版本中提供了)
    public void Btn3OnClick(View view)
    {
        String strTmp = "点击Button03";
        Ev1.setText(strTmp);

    }
}