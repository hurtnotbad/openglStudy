package com.example.lammy.openglstudy;

import android.opengl.GLSurfaceView;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

class LammyRenderer implements GLSurfaceView.Renderer {

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
//        gl.glClearColor(0.1f , 0.4f,0.6f , 1f);

       Log.loge("onSurfaceCreated ...........");
        Native.InitOpenGL();
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
//        gl.glViewport(0,0,width ,height);
        Log.loge("onSurfaceChanged ..........."+width+" "+height);
        Native.OnViewportChanged((float)width ,(float) height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
//        gl.glClear(gl.GL_COLOR_BUFFER_BIT);
  //      Log.loge("onDrawFrame ...........");
            Native.RenderOneFrame();
    }

}
