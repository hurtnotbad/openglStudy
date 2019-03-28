//
// Created by zhangpeng30 on 2019/3/19.
//


#include "ggl.h"
#include "utils.h"
#include "fbo.h"
fbo::fbo() {

}

void fbo::init(int width ,int height){
    // 系统当前的 fbo为0，绘制到屏幕上的fbo,我们读取不到，自己定义fbo可以读取
    //  glGetIntegerv(0x8CA6,(GLint*)prevFbo);
    glGenFramebuffers(1 , &fboObject);
    //启用自创建的fbo
    glBindFramebuffer(GL_FRAMEBUFFER , fboObject);
    //color buffer
    if(colorBuffer[0]==0||colorBuffer[1]==0){
        CreateTexture2D(colorBuffer ,2,nullptr,width,height,GL_RGB);
    }
    // 将创建的texture 挂载到 fbo上
//    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,colorBuffer[(currentColorBufferIndex )%2],0);
//    currentColorBufferIndex = 0;
    //render buffer 只允许opengl自身读取，包含2个buffer，一个depthbuffer 一个 stencil buffer
    //depth buffer

    glGenRenderbuffers(1, &rbo);
    glBindRenderbuffer(GL_RENDERBUFFER,rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8_OES, width, height);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    // 挂载 depth buffer fbo上
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rbo);
    //挂载stencil buffer fbo上
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
    int code = glCheckFramebufferStatus(GL_FRAMEBUFFER);

    if(code != GL_FRAMEBUFFER_COMPLETE){
        LOGE("create fbo fail code = %d" , code);
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}


void fbo::bind(){
    glBindFramebuffer(GL_FRAMEBUFFER , fboObject);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,colorBuffer[(currentColorBufferIndex + 1)%2],0);
    currentColorBufferIndex = (currentColorBufferIndex + 1)%2;
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rbo);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);

}

GLint fbo::getCurrentOutTexture(){
    return colorBuffer[currentColorBufferIndex];
}

void fbo::unBind() {
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}



