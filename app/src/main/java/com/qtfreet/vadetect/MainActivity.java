package com.qtfreet.vadetect;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.ysrc.antiva.AntiVA;

public class MainActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView tv = (TextView) findViewById(R.id.sample_text);
        boolean a = AntiVA.isRunInVa(this);
        boolean b = AntiVA.isMultiOpen(this);
        Log.e("qtfreet0000", "当前是否运行在va环境中： " + a);
        tv.setText("当前是否运行在va环境中： " + a + "\n当前是否运行在多开环境中： " + b + "\n" + getPackageName());
    }


}
