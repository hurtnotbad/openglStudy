#ifdef GL_ES
precision mediump float;
#endif
uniform vec4 U_LightPos;

uniform vec4 U_LightAmbient;
uniform vec4 U_LightDiffuse;
uniform vec4 U_LightSpecular;

uniform vec4 U_AmbientMaterial;
uniform vec4 U_DiffuseMaterial;
uniform vec4 U_SpecularMaterial;

uniform vec4 U_CameraPos;
uniform vec4 U_Option;
uniform sampler2D U_Texture;
varying vec4 V_Color;
varying vec4 V_Normal;
varying vec4 V_WorldPosition;
varying vec2 V_Texcoord;
void main(){

// diffuse 漫反射， ambient 环境光， specular 镜面反射
    vec4 color=vec4(0.0,0.0,0.0,0.0);
    vec4 ambientColor=U_LightAmbient*U_AmbientMaterial;
    vec3 lightPos=U_LightPos.xyz;
    // L 为灯光向量
    vec3 L=lightPos;//-vec3(0,0,0)
    L=normalize(L);
    //单位化 法向量
    vec3 n=normalize(V_Normal.xyz);

    // 计算 漫反射系数，最小为0
    float diffuseIndensity=max(0.0,dot(L,n));
    // 计算漫反射光强度 U_LightDiffuse 光照强度
    vec4 diffuseColor=U_LightDiffuse*U_DiffuseMaterial*diffuseIndensity;
    // 计算镜面反射
    vec4 specularColor=vec4(0.0,0.0,0.0,0.0);
    if(diffuseIndensity>0.0){
        vec3 reflectDir=normalize(reflect(-L,n));// 反射方向
        vec3 viewDir=normalize(U_CameraPos.xyz-V_WorldPosition.xyz);// 观看方向
        // 计算镜面反射强度
        specularColor=U_LightSpecular*U_SpecularMaterial*pow(max(0.0,dot(viewDir,reflectDir)),32.0);
    }
    if(U_Option.x==1.0){
        color=ambientColor+diffuseColor+texture2D(U_Texture,V_Texcoord)+specularColor;
    }else{
        color=ambientColor+diffuseColor+texture2D(U_Texture,V_Texcoord);
    }
    gl_FragColor=color;
}