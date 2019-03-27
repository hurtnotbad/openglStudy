//#version 120
# ifdef GL_ES // 如果是es的环境
precision mediump float;
//varying vec4 V_Color;
uniform sampler2D U_texture;
varying vec2 V_Texcoord;
#endif
/**
* 也是多个块 运算的 并行运算
*/
void main() {
    gl_FragColor = texture2D(U_texture, V_Texcoord);

}
