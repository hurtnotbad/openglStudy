//
// Created by zhangpeng30 on 2019/3/27.
//

#pragma

#include "ggl.h"
class noFilter{

public:
    GLuint textureId,program,vPositionLocation,inputTextureCoordinateLocation,modelMatrixLocation,vTextureLocation,vbo;
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
    noFilter();
    void init();
    void  setTexture(GLuint textureAddress);
    void draw();
private:
    void initUniform();
    void setUniform();
    void onBindTexture();



};