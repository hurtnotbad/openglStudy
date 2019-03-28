//
// Created by zhangpeng30 on 2019/3/19.
//

#pragma
#include "ggl.h"


class fbo
{
    public:
        // 创建2个
        GLuint fboObject ,  rbo; GLuint colorBuffer[2];
        int currentColorBufferIndex = 0;
    public:
        fbo();
        void init(int width ,int height);
        void bind();
        void unBind();
        GLint getCurrentOutTexture();
};
