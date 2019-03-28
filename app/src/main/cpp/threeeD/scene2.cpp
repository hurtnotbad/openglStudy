//
// Created by zhangpeng30 on 2019/3/19.
//

#include "scene.h"
#include "ggl.h"
#include "utils.h"
#include "ThreeDCoordinates.h"
#include "model.h"


GLuint program;
GLint texture;
// 不初始化就是单位矩阵
glm::mat4  viewMatrix, projectMatrix;

ThreeDCoordinates threeDCoordinates;
model model;
glm::vec3 cameraPos =glm::vec3(10.0f,10.0f,10.0f)  , vPos = glm::vec3(0.0f,0.0f,0.0f);
void Init(){
    glClearColor(0.1f,0.4f,0.6f,1.0f);

    // 相机位置、视点、向上向量
    viewMatrix=glm::lookAt(cameraPos,vPos,glm::vec3(0.0f,1.0f,0.0f));
    threeDCoordinates.Init();

    model.InitModel("model/Sphere.obj","model/earth.bmp");
//    model.InitModel("model/niutou.obj","model/niutou.bmp");


}
void SetViewPortSize(float width , float height){
    glViewport(0,0,width,height);
    // 参数分别为，视角，宽高比、最近看到的距离、最远看到的距离
    projectMatrix = glm::perspective(45.0f, width/height , 0.1f , 100.0f);
}
    void Draw(){

//    translateCamera(glm::vec3(-1.0f , -1.0f ,-1.0f), 0.01f);
//        changeDirection(glm::vec3(1.0f , 0.0f ,0.0f),0.010f);
        viewMatrix=glm::lookAt(cameraPos,vPos,glm::vec3(0.0f,1.0f,0.0f));
//        model.rotateMode(glm::vec3(0.0f , 1.0f ,0.0f) ,0.10f );

        threeDCoordinates.Draw(viewMatrix,projectMatrix);
        model.Draw(glm::vec4(cameraPos,1.0f),viewMatrix,projectMatrix);

    }

// 相当于人移动,那就是 视点 和  相机位置,按照 一定方向 移动
    void translateCamera(glm::vec3 translateVector, float ra){
        translateVector = glm::normalize(translateVector)*ra;
        glm::mat4 translateMatrix;
        translateMatrix= glm::translate(translateMatrix,translateVector);

        glm::vec4 newCameraPos =  translateMatrix*(glm::vec4(cameraPos[0] , cameraPos[1] , cameraPos[2], 1.0f));
        glm::vec4 newVPos =  translateMatrix*(glm::vec4(vPos[0] , vPos[1] , vPos[2], 1.0f));

        cameraPos[0] = newCameraPos[0];
        cameraPos[1] = newCameraPos[1];
    cameraPos[2] = newCameraPos[2];

    vPos[0] = newVPos[0];
    vPos[1] = newVPos[1];
    vPos[2] = newVPos[2];

}

// 改变视野方向,就是改变视点的方向
void changeDirection(glm::vec3 rotateVector, float ra) {
    rotateVector = glm::normalize(rotateVector)*ra;
    glm::mat4 translateMatrix;
    translateMatrix= glm::translate(translateMatrix,rotateVector);

    glm::vec4 newVPos =  translateMatrix*(glm::vec4(vPos[0] , vPos[1] , vPos[2], 1.0f));


    vPos[0] = newVPos[0];
    vPos[1] = newVPos[1];
    vPos[2] = newVPos[2];

}
