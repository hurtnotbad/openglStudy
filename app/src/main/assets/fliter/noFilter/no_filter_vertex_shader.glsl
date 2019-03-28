attribute vec4 vPosition;
uniform mat4 modelMatrix;
attribute vec2 inputTextureCoordinate;
varying vec2 textureCoordinate;
void main()
           {
             gl_Position = vPosition;//vec4(vPosition.xyz,1.0);//modelMatrix*
             textureCoordinate = inputTextureCoordinate;
           }