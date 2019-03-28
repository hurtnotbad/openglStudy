//
// Created by zhangpeng30 on 2019/3/27.
//

#include <include/noFilter.h>
#include <include/fbo.h>
#include <include/grayFilter.h>
#include <include/gaussFilter.h>
#include "drawer.h"
#include "ggl.h"
#include "utils.h"
noFilter noFilter1;
grayFilter grayFilter1;
gaussFilter gaussFilter1;
fbo fbo1;
GLuint  textureBmp;
void drawer::Init() {
    glClearColor(0.1f,0.4f,0.6f,1.0f);

    textureBmp = CreateTextureFromBMP("wh.bmp");
    noFilter1.init();
    grayFilter1.init();
    gaussFilter1.init();
    noFilter1.setTexture(textureBmp);

}

void drawer::SetViewPortSize(float width, float height) {
    LOGE("SetViewPortSize");
    glViewport(0,0,width,height);
    LOGE(" width ,height = [%d , %d]  ",width,height);
    fbo1.init(width,height);
    gaussFilter1.setSize(width,height);
}

void drawer::Draw() {

    fbo1.bind();
    noFilter1.draw();
    fbo1.unBind();

//    grayFilter1.setTexture(fbo1.getCurrentOutTexture());
//    grayFilter1.draw();
    gaussFilter1.setTexture(fbo1.getCurrentOutTexture());
    gaussFilter1.draw();


}
