////
//// Created by zhangpeng30 on 2019/3/19.
////
//
//#include "scene.h"
//#include "ggl.h"
//#include "utils.h"
//#include "glm/glm/gtc/matrix_transform.hpp"
//#include "glm/glm/ext.hpp"
//#include "glm/glm/detail/_noise.hpp"
//
//// 将数据从cpu放到 gpu
//GLuint vbo, ebo;
//GLuint program;
//GLint positionLocation,modelMatrixLocation,viewMatrixLocation,projectMatrixLocation, colorLoction;
//GLint texcoordLocation,textureLocation;
//GLint texture;
//// 不初始化就是单位矩阵
//glm::mat4 modelMatrix ,viewMatrix, projectMatrix;
//void Init(){
//    float data[] = {
//            -0.2f,-0.2f,0.0f , 1.0f,1.0f ,1.0f ,1.0f ,1.0f ,0.0f, 0.0f,
//            0.2f, -0.2f ,0.0f , 1.0f,0.0f, 1.0f , 0.0f, 1.0f,1.0f,0.0f,
//            0.0f, 0.2f , 0.0f , 1.0f, 1.0f, 0.0f , 0.0f, 1.0f,0.5f,1.0f
//    };
//
//
//    // 创建vbo 将数据送向显存，并返回存储位置
//    vbo = CreateVBO(sizeof(float)*30 ,data);
//
//    //  利用element绘制 ebo来控制绘制点的顺序
//    unsigned short indexes[] = {0, 1, 2};
//    ebo = CreateEBO(sizeof(unsigned short)*3 ,indexes);
//
//
//    int fileSize = 0;
//    unsigned  char * shaderCode = LoadFileContent("test.vs",fileSize);
//    GLuint vsShader = CompileShader(GL_VERTEX_SHADER,(char *)shaderCode);
//    delete shaderCode;
//    shaderCode = LoadFileContent("test.fs.glsl", fileSize);
//    GLint fsShader = CompileShader(GL_FRAGMENT_SHADER , (char *)shaderCode);
//    program = CreateProgram(vsShader , fsShader);
//    glDeleteShader(vsShader);
//    glDeleteShader(fsShader);
//
//    // attribute 的插槽 和 uniform插槽 不一样，并且都是从0 开始的
//    positionLocation = glGetAttribLocation(program, "position");
//    colorLoction = glGetAttribLocation(program, "color");
//    modelMatrixLocation = glGetUniformLocation(program , "ModelMatrix");
//    viewMatrixLocation = glGetUniformLocation(program , "ViewMatrix");
//    projectMatrixLocation = glGetUniformLocation(program , "ProjectionMatrix");
//    textureLocation = glGetUniformLocation(program , "U_texture");
//    texcoordLocation = glGetAttribLocation(program , "texcoord");
//
//    glm::mat4 model;
//    modelMatrix = glm::translate(model , glm::vec3(0.0f, 0.0f, -0.6f));
//    texture = CreateTextureFromBMP("test2.bmp");
//}
//void SetViewPortSize(float width , float height){
//    glViewport(0,0,width,height);
//    // 参数分别为，视角，宽高比、最近看到的距离、最远看到的距离
//    projectMatrix = glm::perspective(45.0f, width/height , 0.1f , 1000.0f);
//}
//void Draw(){
//
//    glClearColor(0.1f,0.4f,0.6f,1.0f);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    glUseProgram(program);
//
//    glUniformMatrix4fv(modelMatrixLocation , 1 , GL_FALSE , glm::value_ptr(modelMatrix));
//    glUniformMatrix4fv(viewMatrixLocation , 1 , GL_FALSE , glm::value_ptr(viewMatrix));
//    glUniformMatrix4fv(projectMatrixLocation , 1 , GL_FALSE , glm::value_ptr(projectMatrix));
//
//    glBindTexture(GL_TEXTURE_2D, texture);
//    glUniform1i(textureLocation,0);
//
//    glBindBuffer(GL_ARRAY_BUFFER, vbo);
//    glEnableVertexAttribArray(positionLocation);
//    glEnableVertexAttribArray(texcoordLocation);
//    glEnableVertexAttribArray(colorLoction);
//    // 参数说明： GL_FALSE 表示是否需要将数据映射到0-1，这里本来是浮点，不需要；
//    //0 表示vbo 中数据的起始位置
//    glVertexAttribPointer(positionLocation , 4 , GL_FLOAT , GL_FALSE , sizeof(float)*10, 0);
//    glVertexAttribPointer(colorLoction , 4 , GL_FLOAT , GL_FALSE , sizeof(float)*10, (void *)(sizeof(float)*4));
//    glVertexAttribPointer(texcoordLocation , 2 , GL_FLOAT , GL_FALSE , sizeof(float)*10, (void *)(sizeof(float)*8));
//
////    glDrawArrays(GL_TRIANGLES, 0 , 3);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
//    glDrawElements(GL_TRIANGLES , 3 , GL_UNSIGNED_SHORT, 0 );
//
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glUseProgram(0);
//}