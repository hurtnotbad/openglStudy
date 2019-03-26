package com.example.lammy.openglstudy;

import android.content.Context;

import android.opengl.GLSurfaceView;
import android.util.AttributeSet;

public class LammyGLSurfaceView extends GLSurfaceView {
    private LammyRenderer lammyRenderer;
    public LammyGLSurfaceView(Context context) {
        super(context);
        init();
    }

    public LammyGLSurfaceView(Context context, AttributeSet attrs) {
        super(context, attrs);
        init();
    }

    private void  init(){
        lammyRenderer = new LammyRenderer();
        Native.InitAssetManager(getContext().getAssets());
        // 这里申请 2 版本环境，若想3 则需要在 jni层面去做
        setEGLContextClientVersion(2);
        setRenderer(lammyRenderer);
    }

}

