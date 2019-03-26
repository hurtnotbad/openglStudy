package com.example.lammy.openglstudy;

import android.content.res.AssetManager;
public class Native {

    static {
        System.loadLibrary("native-lib");
    }

    public static native void InitAssetManager(AssetManager am);
    public static native void InitOpenGL();
    public static native void OnViewportChanged(float width, float height);
    public static native void RenderOneFrame();

}
