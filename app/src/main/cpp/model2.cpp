//// Created by zhangpeng30 on 2019/3/20.
////
//
//#include "utils.h"
//#include "model.h"
//#include <sstream>
//#include <cstdlib>
//#include "ggl.h"
//#include "glm/glm/gtc/type_ptr.inl"
//#include "glm/glm/gtc/matrix_transform.hpp"
//model::model() {
//
//}
//char * LoadModelFile(AAssetManager* aAssetManager,const char *path , int &filesSize){
//
//     char * fileContent = nullptr;
//    filesSize = 0 ;
//    AAsset * asset = AAssetManager_open(aAssetManager, path , AASSET_MODE_UNKNOWN);
//    if(asset== nullptr){
//        LOGE("LoadFileContent asset is null, load shader error ");
//        return  nullptr;
//    }
//    filesSize = AAsset_getLength(asset);
//    fileContent = new char[filesSize + 1];
//    AAsset_read(asset , fileContent,filesSize);
//    fileContent[filesSize]='\0';
//    AAsset_close(asset);
//    //LOGE("LoadFileContent success ...%s",path);
//    return fileContent;
//
//}
//
//unsigned int* vectorIntToArray(std::vector<unsigned int> array){
//    int size = array.size();
//    unsigned int *a = new unsigned int[size];
//
//    for(int i = 0 ; i < size ; i ++)
//    {
//        a[i] = array[i];
//    }
//    return a;
//}
//float* vectorIntToArray(std::vector< float> array){
//    int size = array.size();
//    float *a = new float[size];
//    for(int i = 0 ; i < size ; i ++)
//    {
//        a[i] = array[i];
////        LOGE(" a[%d] = %f " , i ,a[i] );
////        LOGE(" a[0] = %f "  ,a[0] );
//    }
//
//    return a;
//
//}
//float * array;
//void model::InitModel(const char*modelFilePath,const char*textureImagePath) {
//
//    std::vector<float> texCoord;
//    std::vector<float> normal;
//    std::vector<float> points;
//    std::vector<unsigned int>vertexIndex_Indexs;
//    std::vector<int> vertexIndex;
//    std::vector<float> vertexInfo;
//
//    //load model from file
//    int fileSize = 0;
//    char *fileContent = LoadModelFile(aAssetManager, modelFilePath, fileSize);
//    LOGE("/***********************model start********************************/");
////    LOGE("model = %s" , fileContent);
////    LOGE("/***********************model voer********************************/");
//    std::stringstream ssFileContent(fileContent);
//    char szOneLine[256];//申请一行的数据空间
//    while (!ssFileContent.eof())// 如果文件没有结尾
//    {
//        // 初始化 申请内存，将当前位置后面的数据 用 0代替
//        memset(szOneLine, 0, 256);
//        // 获得一行的数据
//        ssFileContent.getline(szOneLine, 256);
//        if (strlen(szOneLine) > 0) {
//            std::stringstream ssOneLine(szOneLine);
//            std::string temp;
//            if (szOneLine[0] == 'v') {
//                if (szOneLine[1] == 't') {
//                    float a, b;
//                    ssOneLine >> temp;//vt
//                    ssOneLine >> a;
//                    ssOneLine >> b;
//                    texCoord.push_back(a);
//                    texCoord.push_back(b);
//                } else if (szOneLine[1] == 'n') {
//              //      LOGE("normal : %s\n", szOneLine);
//                    float a, b, c;
//                    ssOneLine >> temp;//v
//                    ssOneLine >> a;
//                    ssOneLine >> b;
//                    ssOneLine >> c;
//
//                    normal.push_back(a);
//                    normal.push_back(b);
//                    normal.push_back(c);
//                } else {
//             //       LOGE("position : %s\n", szOneLine);
//                    float a, b, c;
//                    ssOneLine >> temp;//v
//                    ssOneLine >> a;
//                    ssOneLine >> b;
//                    ssOneLine >> c;
//
//                    points.push_back(a);
//                    points.push_back(b);
//                    points.push_back(c);
////                    points.push_back(point);
//                }
//            } else if (szOneLine[0] == 'f') {
//                ssOneLine >> temp;//去掉f
//                std::string vertexStr;
//
//                for (int i = 0; i < 3; ++i)
//                {
//                    //ssOneLine>> 是以空格为分隔符，一次输出一个字符串
//                    ssOneLine >> vertexStr;
//           //         LOGE("vertexStr %s ",vertexStr.c_str());
//                    size_t pos = vertexStr.find_first_of('/');
//                    std::string positionIndexStr = vertexStr.substr(0, pos);
//                    size_t pos2 = vertexStr.find_first_of('/', pos + 1);
//                    std::string texcoordIndexStr = vertexStr.substr(pos + 1, pos2 - pos - 1);
//                    std::string normalIndexStr = vertexStr.substr(pos2 + 1, vertexStr.length() - pos2 - 1);
//
//                    int a, b, c;
//                    a = atoi(positionIndexStr.c_str());//转化为整数
//                    b = atoi(texcoordIndexStr.c_str());
//                    c = atoi(normalIndexStr.c_str());
//                    vertexIndex.push_back(a);
//                    vertexIndex.push_back(b);
//                    vertexIndex.push_back(c);
//
//
//
//                }
//
//            }
//        }
//    }
//    delete fileContent;
//
//
//
//    LOGE("vertexIndex.size() = %d ",vertexIndex.size());
//    for(int i = 0 ; i <vertexIndex.size(); i= i+3){
//
//        int point_index = vertexIndex[i] - 1;
//        int tx_index = vertexIndex[i + 1] - 1;
//        int normal_index = vertexIndex[i + 2] - 1;
//
//
//        vertexInfo.push_back(points[point_index*3]);
//        vertexInfo.push_back(points[point_index*3+1]);
//        vertexInfo.push_back(points[point_index*3+2]);
//
//        vertexInfo.push_back(texCoord[tx_index*2]);
//        vertexInfo.push_back(texCoord[tx_index*2+1]);
//
//
//        vertexInfo.push_back(normal[normal_index*3]);
//        vertexInfo.push_back(normal[normal_index*3+1]);
//        vertexInfo.push_back(normal[normal_index*3+2]);
//
//    }
//
//
//    pointsNumber = vertexInfo.size()/8;
//    LOGE("pointsNumber = %d ",int(pointsNumber));
//    glGenBuffers(1, &mVBO);
//    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
//    attributeData = vectorIntToArray(vertexInfo);
//    glBufferData(GL_ARRAY_BUFFER,sizeof(float)*vertexInfo.size(),attributeData,GL_STATIC_DRAW);
////    glBufferSubData(GL_ARRAY_BUFFER,0,sizeof(Vertex)*mVertexCount,mVertexes);
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//    CreateModelProgram("model/earth_vs.glsl","model/earth_fs.glsl");
//    mTexcoordLocation=glGetAttribLocation(program,"texcoord");
//    positionLocation = glGetAttribLocation(program, "position");
//    //colorLoction = glGetAttribLocation(program, "color");
//    modelMatrixLocation = glGetUniformLocation(program , "ModelMatrix");
//    U_textureLoacation = glGetUniformLocation(program , "U_texture");
//    viewMatrixLocation = glGetUniformLocation(program , "ViewMatrix");
//    projectMatrixLocation = glGetUniformLocation(program , "ProjectionMatrix");
//
//    mNormalLocation=glGetAttribLocation(program,"normal");
//    if(textureImagePath != nullptr && textureImagePath != "") {
//        texture = CreateTextureFromBMP(textureImagePath);
//    }
//
//}
//void model::Bind( glm::mat4 viewMatrix,glm::mat4 projectionMatrix)
//{
//
////    modelMatrix= glm::translate(modelMatrix,glm::vec3(0.0f,0.0f,0.0f));
//    glUseProgram(program);
//    glUniformMatrix4fv(modelMatrixLocation,1,GL_FALSE,glm::value_ptr(modelMatrix));
//    glUniformMatrix4fv(viewMatrixLocation,1,GL_FALSE,glm::value_ptr(viewMatrix));
//    glUniformMatrix4fv(projectMatrixLocation,1,GL_FALSE,glm::value_ptr(projectionMatrix));
//
//
//    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
//    glEnableVertexAttribArray(positionLocation);
//    glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, sizeof(float)*8, 0);
//
//    glEnableVertexAttribArray(mTexcoordLocation);
//    glVertexAttribPointer(mTexcoordLocation, 2, GL_FLOAT, GL_FALSE, sizeof(float)*8, (void*)(sizeof(float) * 3));
//
//    glEnableVertexAttribArray(mNormalLocation);
//    glVertexAttribPointer(mNormalLocation, 3, GL_FLOAT, GL_FALSE, sizeof(float)*8, (void*)(sizeof(float) * 5));
//
//    glActiveTexture(GL_TEXTURE0 + 0);
//    glBindTexture(GL_TEXTURE_2D,texture);
//    glUniform1i(U_textureLoacation,0);
//}
//
//void model::Draw( glm::mat4 viewMatrix,glm::mat4 projectionMatrix) {
//
//    glUseProgram(program);
//    glEnable(GL_DEPTH_TEST);
//    glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));
//    glUniformMatrix4fv(projectMatrixLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
//    Bind(viewMatrix, projectionMatrix);
//
//    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
////    glDrawArrays(GL_TRIANGLES,0,pointsNumber);
////    glDrawArrays(GL_TRIANGLE_STRIP,0,pointsNumber);
//    glDrawArrays(GL_TRIANGLES,0,pointsNumber);
//
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glUseProgram(0);
//}
//
//void model::CreateModelProgram(const char * vsPath , const char * fsPath){
//    int fileSize = 0;
//    unsigned  char * shaderCode = LoadFileContent(vsPath,fileSize);
//    GLuint vsShader = CompileShader(GL_VERTEX_SHADER,(char *)shaderCode);
//    delete shaderCode;
//    shaderCode = LoadFileContent(fsPath, fileSize);
//    GLint fsShader = CompileShader(GL_FRAGMENT_SHADER , (char *)shaderCode);
//    program = CreateProgram(vsShader , fsShader);
//    glDeleteShader(vsShader);
//    glDeleteShader(fsShader);
//
//}
//
//
//
