package com.example.buildso;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;


public class MainActivity extends AppCompatActivity {

    // Used to load the 'buildso' library on application startup.
    static {
        System.loadLibrary("buildso");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.d("APP", stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'buildso' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}