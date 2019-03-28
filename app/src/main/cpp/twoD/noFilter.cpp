#include "noFilter.h"
#include "utils.h"
#include "ggl.h"

noFilter::noFilter() {

}
void noFilter::init() {
    LOGE("noFilter create");
    program = CreateProgram("fliter/noFilter/no_filter_vertex_shader.glsl" ,"fliter/noFilter/no_filter_fragment_shader.glsl" );
    initUniform();
    vbo = CreateVBO(sizeof(data) ,data);
}
void noFilter::setTexture(GLuint textureAddress) {
    textureId = textureAddress;
}


void noFilter::initUniform() {
    vPositionLocation = glGetAttribLocation(program, "vPosition");
    inputTextureCoordinateLocation = glGetAttribLocation(program, "inputTextureCoordinate");
    modelMatrixLocation = glGetUniformLocation(program, "modelMatrix");
    vTextureLocation = glGetUniformLocation(program, "vTexture");

}

void noFilter::setUniform() {
//    glVertexAttribPointer(positionLocation , 4 , GL_FLOAT , GL_FALSE , sizeof(float)*7, 0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(vPositionLocation, 3, GL_FLOAT, GL_FALSE, sizeof(float)*5, 0 );
    glVertexAttribPointer(inputTextureCoordinateLocation, 2, GL_FLOAT, GL_FALSE, sizeof(float)*5, (void*)(sizeof(float)*3 ));
    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));
}

void noFilter::onBindTexture() {
    glActiveTexture(GL_TEXTURE0 + 0);
    glBindTexture(GL_TEXTURE_2D,textureId);
    glUniform1i(vTextureLocation,0);
}

void noFilter::draw() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(program);
    setUniform();
    onBindTexture();

    glEnableVertexAttribArray(vPositionLocation);
    glEnableVertexAttribArray(inputTextureCoordinateLocation);

    glDrawArrays(GL_TRIANGLE_STRIP,0,4);//

    // Disable vertex array
    glDisableVertexAttribArray(vPositionLocation);
    glDisableVertexAttribArray(inputTextureCoordinateLocation);
}



