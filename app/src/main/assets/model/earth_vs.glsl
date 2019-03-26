attribute vec4 position;
//attribute vec4 color;
attribute vec3 texcoord;
attribute vec3 normal;
uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;
//uniform mat4 IT_ModelMatrix;
//varying vec4 V_Color;
//varying vec4 V_Normal;
//varying vec4 V_WorldPosition;
varying vec2 V_Texcoord;
void main(){

//    V_Normal=IT_ModelMatrix*normal;
//    V_WorldPosition=ModelMatrix*position;
//    V_Texcoord=texcoord.xy;
    V_Texcoord=texcoord.xy;
    gl_Position=ProjectionMatrix*ViewMatrix*ModelMatrix*position;
//    gl_Position=position;

}