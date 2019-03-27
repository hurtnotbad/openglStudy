//
// Created by zhangpeng30 on 2019/3/20.
//

#ifndef OPENGLSTUDY_MODEL_H
#define OPENGLSTUDY_MODEL_H

#include "ggl.h"
#endif //OPENGLSTUDY_MODEL_H
class model
{
public:
    GLuint mVBO, mIBO;
    unsigned int pointsNumber;
    unsigned int mIndexCount;
    float* attributeData;
    GLint program;
    glm::mat4 modelMatrix;
    GLint positionLocation,colorLoction,viewMatrixLocation,projectMatrixLocation,modelMatrixLocation,mTexcoordLocation,mNormalLocation,U_textureLoacation;
    GLint U_LightAmbientLocation,U_LightPosLocation,U_CameraPosLocation,U_LightDiffuseLocation,U_LightSpecularLocation,U_AmbientMaterialLocation,U_DiffuseMaterialLocation;
    GLint U_SpecularMaterialLocation,U_OptionLocation,IT_ModelMatrixLocation;
    GLint texture;
    glm::vec3 position = glm::vec3(0.0f ,0.0f ,0.0f);
public:
    model();
    void setLightArgs(glm::vec4 cameraPos);
    void InitModel(const char*modelFilePath,const char*textureImagePath);
    void Bind( glm::vec4 cameraPos,glm::mat4 viewMatrix,glm::mat4 projectionMatrix);
    void Draw( glm::vec4 cameraPos ,glm::mat4 viewMatrix,glm::mat4 projectionMatrix);
    void CreateModelProgram(const char * vsPath , const char * fsPath);

    void translateMode(glm::vec3 vec , float v);
    void setPosition(float x , float y , float z);
    void rotateMode(glm::vec3 v , float angel);
};


