attribute vec4 position;
attribute vec4 color;
varying vec4 V_Color;

uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;



/***
*   gpu 是有很多个核，因此计算每个点到屏幕的位置是 并行计算的
*/
void main(){

    V_Color = color;
    gl_Position = ProjectionMatrix*ViewMatrix*ModelMatrix*position;//
//    V_Texcoord = texcoord;
}
