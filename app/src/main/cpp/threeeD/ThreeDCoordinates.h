
#pragma once

#include "ggl.h"



class ThreeDCoordinates{
public:
    float data[28]=  {
            0.0f, 0.0f , 0.0f   ,1.0f,  1.0f,1.0f,1.0f,
            0.0f, 10.0f , 0.0f ,1.0f,   0.0f, 1.0f, 0.0f,
            10.0f, 0.0f , 0.0f, 1.0f,    0.0f,0.0f,1.0f,
            0.0f, 0.0f, 10.0f  ,1.0f,   1.0f,0.0f, 0.0f};
    unsigned short indexes[8] = {0, 1, 0,2,0,3};
    GLint program,vbo,ebo;
    glm::mat4 modelMatrix;
    GLint positionLocation,colorLoction,viewMatrixLocation,projectMatrixLocation,modelMatrixLocation;
public:
    ThreeDCoordinates();
    void Init();

    void Bind(glm::mat4 &viewMatrix, glm::mat4 &projectMatrix);

    void  Draw(glm::mat4 &viewMatrix, glm::mat4 &projectMatrix);

private:
    void createProgram(const char* vsPath ,const char* fsPath);

};
