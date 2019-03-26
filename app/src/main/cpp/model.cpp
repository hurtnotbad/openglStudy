// Created by zhangpeng30 on 2019/3/20.
//

#include "utils.h"
#include "model.h"
#include <sstream>
#include <cstdlib>
#include "ggl.h"
#include "glm/glm/gtc/type_ptr.inl"
#include "glm/glm/gtc/matrix_transform.hpp"
model::model() {

}
char * LoadModelFile(AAssetManager* aAssetManager,const char *path , int &filesSize){

     char * fileContent = nullptr;
    filesSize = 0 ;
    AAsset * asset = AAssetManager_open(aAssetManager, path , AASSET_MODE_UNKNOWN);
    if(asset== nullptr){
        LOGE("LoadFileContent asset is null, load shader error ");
        return  nullptr;
    }
    filesSize = AAsset_getLength(asset);
    fileContent = new char[filesSize + 1];
    AAsset_read(asset , fileContent,filesSize);
    fileContent[filesSize]='\0';
    AAsset_close(asset);
    //LOGE("LoadFileContent success ...%s",path);
    return fileContent;

}

unsigned int* vectorIntToArray(std::vector<unsigned int> array){
    int size = array.size();
    unsigned int *a = new unsigned int[size];

    for(int i = 0 ; i < size ; i ++)
    {
        a[i] = array[i];
    }
    return a;
}
float* vectorIntToArray(std::vector< float> array){
    int size = array.size();
    float *a = new float[size];
    for(int i = 0 ; i < size ; i ++)
    {
        a[i] = array[i];
//        LOGE(" a[%d] = %f " , i ,a[i] );
//        LOGE(" a[0] = %f "  ,a[0] );
    }

    return a;

}

void model::InitModel(const char*modelFilePath,const char*textureImagePath) {

    std::vector<float> texCoord;
    std::vector<float> normal;
    std::vector<float> points;
    std::vector<unsigned int>vertexIndex_Indexs;
    std::vector<int> vertexIndex;
    std::vector<float> vertexInfo;

    //load model from file
    int fileSize = 0;
    char *fileContent = LoadModelFile(aAssetManager, modelFilePath, fileSize);
    LOGE("/***********************model start********************************/");
//    LOGE("model = %s" , fileContent);
//    LOGE("/***********************model voer********************************/");
    std::stringstream ssFileContent(fileContent);
    char szOneLine[256];//申请一行的数据空间
    while (!ssFileContent.eof())// 如果文件没有结尾
    {
        // 初始化 申请内存，将当前位置后面的数据 用 0代替
        memset(szOneLine, 0, 256);
        // 获得一行的数据
        ssFileContent.getline(szOneLine, 256);
        if (strlen(szOneLine) > 0) {
            std::stringstream ssOneLine(szOneLine);
            std::string temp;
            if (szOneLine[0] == 'v') {
                if (szOneLine[1] == 't') {
                    float a, b;
                    ssOneLine >> temp;//vt
                    ssOneLine >> a;
                    ssOneLine >> b;
                    texCoord.push_back(a);
                    texCoord.push_back(b);
                } else if (szOneLine[1] == 'n') {
              //      LOGE("normal : %s\n", szOneLine);
                    float a, b, c;
                    ssOneLine >> temp;//v
                    ssOneLine >> a;
                    ssOneLine >> b;
                    ssOneLine >> c;

                    normal.push_back(a);
                    normal.push_back(b);
                    normal.push_back(c);
                } else {
             //       LOGE("position : %s\n", szOneLine);
                    float a, b, c;
                    ssOneLine >> temp;//v
                    ssOneLine >> a;
                    ssOneLine >> b;
                    ssOneLine >> c;

                    points.push_back(a);
                    points.push_back(b);
                    points.push_back(c);
//                    points.push_back(point);
                }
            } else if (szOneLine[0] == 'f') {
                ssOneLine >> temp;//去掉f
                std::string vertexStr;

                for (int i = 0; i < 3; ++i)
                {
                    //ssOneLine>> 是以空格为分隔符，一次输出一个字符串
                    ssOneLine >> vertexStr;
           //         LOGE("vertexStr %s ",vertexStr.c_str());
                    size_t pos = vertexStr.find_first_of('/');
                    std::string positionIndexStr = vertexStr.substr(0, pos);
                    size_t pos2 = vertexStr.find_first_of('/', pos + 1);
                    std::string texcoordIndexStr = vertexStr.substr(pos + 1, pos2 - pos - 1);
                    std::string normalIndexStr = vertexStr.substr(pos2 + 1,
                                                                  vertexStr.length() - pos2 - 1);

                    int a, b, c;
                    a = atoi(positionIndexStr.c_str());//转化为整数
                    b = atoi(texcoordIndexStr.c_str());
                    c = atoi(normalIndexStr.c_str());

                    int size = vertexIndex.size()/3;

                    int indexi = -1;
                    for(int i=0 ; i<size ; i ++){
                        if(a == vertexIndex[i*3] && b == vertexIndex[i*3 + 1] && c == vertexIndex[i*3 +2])
                        {
                            indexi = i;
                            break;
                        }
                    }
                    if(indexi == -1){
                        indexi = vertexIndex.size()/3;
                        vertexIndex.push_back(a);
                        vertexIndex.push_back(b);
                        vertexIndex.push_back(c);
//                        LOGE("a  = %d,b  = %d,c  = %d ",a , b, c);
                    }
                    vertexIndex_Indexs.push_back(indexi);



                }

            }
        }
    }
    delete fileContent;
    LOGE("/***********************model end********************************/");
//    // 验证face 是否 正确
//    for(int i = 0 ; i < vertexIndex_Indexs.size(); i++) {
//
//        int vertexInfo_id = vertexIndex_Indexs[i]* 3;
//        int point_index = vertexIndex[vertexInfo_id];
//        int tx_index = vertexIndex[vertexInfo_id + 1] ;
//        int normal_index = vertexIndex[vertexInfo_id + 2];
//        LOGE("[v = %d , tx = %d, nor = %d]", point_index, tx_index , normal_index);
//        LOGE("");
//    }

/***
 *  根据 index_index 来获取 每个vertx的index，再根据vertex的index 获取真正的点
 */


    for(int i = 0 ; i <vertexIndex.size(); i= i+3){

        int point_index = vertexIndex[i] - 1;
        int tx_index = vertexIndex[i + 1] - 1;
        int normal_index = vertexIndex[i + 2] - 1;


        vertexInfo.push_back(points[point_index*3]);
        vertexInfo.push_back(points[point_index*3+1]);
        vertexInfo.push_back(points[point_index*3+2]);

        vertexInfo.push_back(texCoord[tx_index*2]);
        vertexInfo.push_back(texCoord[tx_index*2+1]);


        vertexInfo.push_back(normal[normal_index*3]);
        vertexInfo.push_back(normal[normal_index*3+1]);
        vertexInfo.push_back(normal[normal_index*3+2]);

    }

/**  利用element绘制 ibo来控制绘制点的顺序
 * **/
    unsigned int *indexes = vectorIntToArray(vertexIndex_Indexs) ;
    glGenBuffers(1, &mIBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , mIBO);
    int size  = vertexIndex_Indexs.size();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*size, indexes,GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , 0);

//    for(int i = 0 ; i < size ; i ++){
//        LOGE(" indexes[ %d] = %d  " , i, indexes[i]);
//    }

    mIndexCount = vertexIndex_Indexs.size();
    LOGE(" mIndexCount = %d  " , mIndexCount);
//create vbo
    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    attributeData = vectorIntToArray(vertexInfo);
    glBufferData(GL_ARRAY_BUFFER,sizeof(float)*vertexInfo.size(),attributeData,GL_STATIC_DRAW);
//    glBufferSubData(GL_ARRAY_BUFFER,0,sizeof(Vertex)*mVertexCount,mVertexes);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    CreateModelProgram("model/earth_vs.glsl","model/earth_fs.glsl");
    mTexcoordLocation=glGetAttribLocation(program,"texcoord");
    positionLocation = glGetAttribLocation(program, "position");
    //colorLoction = glGetAttribLocation(program, "color");
    modelMatrixLocation = glGetUniformLocation(program , "ModelMatrix");
    U_textureLoacation = glGetUniformLocation(program , "U_texture");
    viewMatrixLocation = glGetUniformLocation(program , "ViewMatrix");
    projectMatrixLocation = glGetUniformLocation(program , "ProjectionMatrix");

    projectMatrixLocation = glGetUniformLocation(program , "ProjectionMatrix");

    mNormalLocation=glGetAttribLocation(program,"normal");
    if(textureImagePath != nullptr && textureImagePath != "") {
        texture = CreateTextureFromBMP(textureImagePath);
    }

}
void model::Bind( glm::mat4 viewMatrix,glm::mat4 projectionMatrix)
{

//    modelMatrix= glm::translate(modelMatrix,glm::vec3(0.0f,0.0f,0.0f));
    glUseProgram(program);
    glUniformMatrix4fv(modelMatrixLocation,1,GL_FALSE,glm::value_ptr(modelMatrix));
    glUniformMatrix4fv(viewMatrixLocation,1,GL_FALSE,glm::value_ptr(viewMatrix));
    glUniformMatrix4fv(projectMatrixLocation,1,GL_FALSE,glm::value_ptr(projectionMatrix));


    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glEnableVertexAttribArray(positionLocation);
    glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, sizeof(float)*8, 0);

    glEnableVertexAttribArray(mTexcoordLocation);
    glVertexAttribPointer(mTexcoordLocation, 2, GL_FLOAT, GL_FALSE, sizeof(float)*8, (void*)(sizeof(float) * 3));

    glEnableVertexAttribArray(mNormalLocation);
    glVertexAttribPointer(mNormalLocation, 3, GL_FLOAT, GL_FALSE, sizeof(float)*8, (void*)(sizeof(float) * 5));

    glActiveTexture(GL_TEXTURE0 + 0);
    glBindTexture(GL_TEXTURE_2D,texture);
    glUniform1i(U_textureLoacation,0);
}

void model::Draw( glm::mat4 viewMatrix,glm::mat4 projectionMatrix) {

    glUseProgram(program);
    glEnable(GL_DEPTH_TEST);
    glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));
    glUniformMatrix4fv(projectMatrixLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    Bind(viewMatrix, projectionMatrix);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBO);
//    LOGE("mIndexCount = %d", mIndexCount);
    glDrawElements(GL_TRIANGLES,mIndexCount, GL_UNSIGNED_INT, 0);
//    for (int i = 0; i < mIndexCount; i = i+3) {
//    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (void*)(sizeof(unsigned int) * i));
//}

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glUseProgram(0);
}

void model::CreateModelProgram(const char * vsPath , const char * fsPath){
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

void model::translateMode(glm::vec3 vec, float v) {
    vec =  glm::normalize(vec);
//    modelMatrix = glm::translate(modelMatrix, vec*v);
    position[0] = position[0] + vec[0]*v;
    position[1] = position[1] + vec[1]*v;
    position[2] = position[2] + vec[2]*v;
    setPosition( position[0] , position[1] ,position[2] );
}

int i = 0;
void model::rotateMode(glm::vec3 v, float angel) {
    glm::mat4 mat ={
     1.0f , 0.0f, 0.0f, 0.0f
    , 0.0f, 1.0f, 0.0f, 0.0f
    , 0.0f, 0.0f, 1.0f, 0.0f
    , 0.0f, 0.0f, 0.0f, 1.0f
    };
    LOGE("i = %d" , i);
    modelMatrix = glm::rotate(mat, angel*i ,v);
    modelMatrix = glm::translate(modelMatrix, position);
    i++;
//    setPosition(position[0] ,position[1],position[2]);
}

void model::setPosition(float x , float y , float z) {
    glm::mat4 mat;
    modelMatrix = glm::translate(mat, glm::vec3(x, y , z));
    position[0] = x;
    position[1] = y;
    position[2] = z;
}





