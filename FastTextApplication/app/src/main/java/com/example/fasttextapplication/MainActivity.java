package com.example.fasttextapplication;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import android.Manifest;
import android.app.Activity;
import android.content.pm.PackageManager;
import android.content.res.AssetFileDescriptor;
import android.os.Build;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    TextView showresult ;
    String text;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Native.nativeInit("");
        AssetFileDescriptor afd = MainActivity.this.getResources().openRawResourceFd(R.raw.model);
        String path="android.resource://"+getResources().getResourcePackageName(R.raw.model)+"/"+R.raw.model;

        TextView showText = (TextView)findViewById(R.id.show_text);
        showresult = (TextView)findViewById(R.id.show_result);
        //String text = "人 世 间 ， 活 着 就 要 有 等 待 ， 活 着 就 要 有 梦 想 ， 或 等 一 个 人 ， 或 等 一 个 故 事\n";
        text = "最 近 有 传 说 ， 接 吻 不 仅 护 齿 止 痛 ， 甚 至 还 可 以 减 肥 呢\n";
        showText.setText(text);

//        if(Build.VERSION.SDK_INT >= 23) {
//            //判断是否有这个权限
//            if (ContextCompat.checkSelfPermission(MainActivity.this,
//                    Manifest.permission.WRITE_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) {
//                //2、申请权限: 参数二：权限的数组；参数三：请求码
//                ActivityCompat.requestPermissions(MainActivity.this, new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE}, REQUEST_WRITE);
//            } else {
//
//
//                writeToSdCard();
//
//
//            }
//        }
        Native.nativeLoadmodel(path);
        Log.d("djh"," 11111111111111111 " );

        findViewById(R.id.btn_predict).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                int predictclass  = Native.nativePredictProcess(text,2,0);
                String name = null;
                if (predictclass == 0) {
                    name = "女性";
                } else if (predictclass == 1) {
                    name = "文学";
                } else if (predictclass == 2) {
                    name = "校园";
                } else if (predictclass == 3) {
                    name = "体育";
                }
                showresult.setText(name);
            }
        });
//
//        new Thread(new Runnable() {
//            @Override
//            public void run() {
//                for(int i=0;i<8000*150;i++)
//                {
//                    try{
//
//                        Thread.sleep(20);
//
//                    }catch (Exception e ){
//
//
//
//                    }
//                    final long startTimestamp = System.nanoTime();
//                    String text = "人 世 间 ， 活 着 就 要 有 等 待 ， 活 着 就 要 有 梦 想 ， 或 等 一 个 人 ， 或 等 一 个 故 事\n";
////                    String text = "最 近 有 传 说 ， 接 吻 不 仅 护 齿 止 痛 ， 甚 至 还 可 以 减 肥 呢\n";
//                    int predictclass  = Native.nativePredictProcess(text,2,0);
//                    String name = null;
//                    if (predictclass == 0) {
//                        name = "女性";
//                    } else if (predictclass == 1) {
//                        name = "文学";
//                    } else if (predictclass == 2) {
//                        name = "校园";
//                    } else if (predictclass == 3) {
//                        name = "体育";
//                    }
//                    final long endTimestamp = System.nanoTime();
//                    final float inferenceTimeCost = (endTimestamp - startTimestamp) /1000000.0f;
//                    Log.d("djh"," time " + inferenceTimeCost);
//                    Log.d("djh","predictclass " + predictclass);
//
//                }
//
//
//
//
//
//
//            }
//        }).run();

    }
}
