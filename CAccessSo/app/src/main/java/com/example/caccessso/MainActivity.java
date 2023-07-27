package com.example.caccessso;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.example.caccessso.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'caccessso' library on application startup.
    static {
        System.loadLibrary("caccessso");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'caccessso' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}