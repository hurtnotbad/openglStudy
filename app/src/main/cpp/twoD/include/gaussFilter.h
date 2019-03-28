//
// Created by zhangpeng30 on 2019/3/28.
//
//
// Created by zhangpeng30 on 2019/3/27.
//

#pragma

#include "ggl.h"
class gaussFilter{

public:
    GLuint textureId,program,vPositionLocation,inputTextureCoordinateLocation,modelMatrixLocation,vTextureLocation,vbo;
    GLuint wStepLocation ,hStepLocation;
    float widthStep , heightStep;
    glm::mat4 modelMatrix;
    //    //顶点坐标
    float data2[20] = {
            //point\ //tex
            -1.0f,  1.0f, -1.0f,
            0.0f , 0.0f,

            -1.0f, -1.0f,-1.0f,
            0.0f , 1.0f,

            1.0f, 1.0f,-1.0f,
            1.0f , 0.0f,

            1.0f,  -1.0f,-1.0f,
            1.0f , 1.0f

    };
    float data[20] = {
            //point\ //tex
            -1.0f,  1.0f, -1.0f,
            0.0f , 1.0f,

            -1.0f, -1.0f,-1.0f,
            0.0f , 0.0f,

            1.0f, 1.0f,-1.0f,
            1.0f , 1.0f,

            1.0f,  -1.0f,-1.0f,
            1.0f , 0.0f

    };

public:
    gaussFilter();
    void init();
    void  setTexture(GLuint textureAddress);
    void draw();
    void setSize(int width ,int height);
private:
    void initUniform();
    void setUniform();
    void onBindTexture();




};