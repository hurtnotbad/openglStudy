attribute vec4 position;
// 模型视口
uniform mat4 ModelMatrix;

uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;
/***
*   gpu 是有很多个核，因此计算每个点到屏幕的位置是 并行计算的
*/
void main(){

gl_Positon = ProjectionMatrix*ViewMatrix*ModelMatrix*position;

}