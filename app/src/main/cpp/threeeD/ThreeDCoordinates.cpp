//
// Created by zhangpeng30 on 2019/3/24.
//

#include "ggl.h"
#include "ThreeDCoordinates.h"
#include "utils.h"


ThreeDCoordinates::ThreeDCoordinates() {

}
void ThreeDCoordinates::Init() {
    glClearColor(0.1f,0.4f,0.6f,1.0f);
//    modelMatrix= glm::translate(modelMatrix,glm::vec3(0.0f,0.0f,0.0f));
//    modelMatrix= glm::rotate(modelMatrix,45.f,glm::vec3(0.0f,0.0f,0.0f));
//    modelMatrix= glm::scale(modelMatrix,glm::vec3(1.0f,1.0f,1.0f));

    // 创建vbo 将数据送向显存，并返回存储位置
    vbo = CreateVBO(sizeof(float)*28 ,data);

    //  利用element绘制 ebo来控制绘制点的顺序
    ebo = CreateEBO(sizeof(unsigned short)* 6 ,indexes);

    createProgram("3dCoordinates/3dcoord_vs.glsl","3dCoordinates/3dcood_fs.glsl");

    positionLocation = glGetAttribLocation(program, "position");
    colorLoction = glGetAttribLocation(program, "color");
    modelMatrixLocation = glGetUniformLocation(program , "ModelMatrix");
    viewMatrixLocation = glGetUniformLocation(program , "ViewMatrix");
    projectMatrixLocation = glGetUniformLocation(program , "ProjectionMatrix");



}

void ThreeDCoordinates::Bind(glm::mat4 &viewMatrix, glm::mat4 &projectMatrix) {
    // attribute 的插槽 和 uniform插槽 不一样，并且都是从0 开始的
    glUniformMatrix4fv(modelMatrixLocation , 1 , GL_FALSE , glm::value_ptr(modelMatrix));
    glUniformMatrix4fv(viewMatrixLocation , 1 , GL_FALSE , glm::value_ptr(viewMatrix));
    glUniformMatrix4fv(projectMatrixLocation , 1 , GL_FALSE , glm::value_ptr(projectMatrix));



    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glEnableVertexAttribArray(positionLocation);
    glEnableVertexAttribArray(colorLoction);
    // 参数说明： GL_FALSE 表示是否需要将数据映射到0-1，这里本来是浮点，不需要；
    //0 表示vbo 中数据的起始位置
    glVertexAttribPointer(positionLocation , 4 , GL_FLOAT , GL_FALSE , sizeof(float)*7, 0);
    glVertexAttribPointer(colorLoction , 3 , GL_FLOAT , GL_FALSE , sizeof(float)*7, (void *)(sizeof(float)*4));


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);



}

void ThreeDCoordinates::Draw(glm::mat4 &viewMatrix, glm::mat4 &projectMatrix) {

    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(program);
    Bind(viewMatrix ,projectMatrix );
//  glDrawElements(GL_LINEAR , 3 , GL_UNSIGNED_SHORT, 0 );
    glDrawElements(GL_LINES ,6 , GL_UNSIGNED_SHORT , 0 );
//    glDrawArrays(GL_TRIANGLES,0,3);
//    glDrawArrays(GL_LINES,0,2);

    //unbind
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glUseProgram(0);
}



void ThreeDCoordinates::createProgram(const char* vsPath, const char* fsPath) {

    int fileSize = 0;
    unsigned  char * shaderCode = LoadFileContent(vsPath,fileSize);
    GLuint vsShader = CompileShader(GL_VERTEX_SHADER,(char *)shaderCode);
    delete shaderCode;
    shaderCode = LoadFileContent(fsPath, fileSize);
    GLint fsShader = CompileShader(GL_FRAGMENT_SHADER , (char *)shaderCode);
    program = CreateProgram(vsShader , fsShader);
    glDeleteShader(vsShader);
    glDeleteShader(fsShader);

}










