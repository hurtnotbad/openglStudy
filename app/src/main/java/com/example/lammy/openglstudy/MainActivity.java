package com.example.lammy.openglstudy;

import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {


    private LammyGLSurfaceView lammyGLSurfaceView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        lammyGLSurfaceView = new LammyGLSurfaceView(this);
        setContentView(lammyGLSurfaceView);
        Log.loge(Environment.getExternalStorageState());
    }

}
