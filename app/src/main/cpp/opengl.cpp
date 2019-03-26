
#include "ggl.h"
#include "scene.h"
#include "utils.h"


// 启用全局变量，声明在ggl.h 里面

//unsigned char * LoadFileContent(const char *path , int &filesSize){
//
//    unsigned char * fileContent = nullptr;
//    filesSize = 0 ;
//    AAsset * asset = AAssetManager_open(aAssetManager, path , AASSET_MODE_UNKNOWN);
//    if(asset== nullptr){
//        LOGE("LoadFileContent asset is null, load shader error ");
//        return  nullptr;
//    }
//    filesSize = AAsset_getLength(asset);
//    fileContent = new unsigned char[filesSize];
//    AAsset_read(asset , fileContent,filesSize);
//    fileContent[filesSize]='\0';
//    AAsset_close(asset);
//    LOGE("LoadFileContent success ...%s",path);
//    return fileContent;
//
//}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_lammy_openglstudy_Native_InitAssetManager(JNIEnv *env, jclass type, jobject am) {
    aAssetManager = AAssetManager_fromJava(env , am);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_lammy_openglstudy_Native_InitOpenGL(JNIEnv *env, jclass type) {

//    glClearColor(0.1 , 0.4,0.6 , 1);
    Init();
 //   InitModel(aAssetManager , "model/Cube.obj" );
}extern "C"
JNIEXPORT void JNICALL
Java_com_example_lammy_openglstudy_Native_OnViewportChanged(JNIEnv *env, jclass type, jfloat width,
                                                            jfloat height) {
//    glViewport(0,0,width ,height);
    SetViewPortSize(width ,height);

}

float GetFrameTime(){
    static unsigned  long long lastTime = 0,currentTime =0;
    timeval current;
    gettimeofday(&current , nullptr);
    // 将时间转化为毫秒
    currentTime = current.tv_sec * 1000 + current.tv_usec/1000;
    unsigned  long long frameTime = lastTime == 0?0:currentTime - lastTime;
    lastTime = currentTime;
    return float(frameTime)/1000.0f;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_lammy_openglstudy_Native_RenderOneFrame(JNIEnv *env, jclass type) {

//    glClear(GL_COLOR_BUFFER_BIT);
    Draw();
}