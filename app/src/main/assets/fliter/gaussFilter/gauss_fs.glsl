//#extension GL_OES_EGL_image_external : require
precision mediump float;
varying vec2 textureCoordinate;
uniform sampler2D vTexture;
uniform float wStep;
uniform float hStep;

void main()
 {

//int size = 2;
//vec2 near[(size+1)*(size+1)];
//for(int i = -size; i < size; i ++ )
//    for(int j = -size; j < size; j ++ )
//        {
//            j[]
//            near[i] = vec2(i*wStep , i*hStep);
//    }
    vec2 near[9];
    near[0] = vec2(-wStep,-hStep);
    near[1] = vec2(0.0,-hStep);
    near[2] = vec2(wStep,-hStep);
    near[3] = vec2(-wStep,0.0);
    near[4] = vec2(0.0,0.0);
    near[5] = vec2(wStep,0.0);
    near[6] = vec2(-wStep,hStep);
    near[7] = vec2(0.0,hStep);
    near[8] = vec2(wStep,hStep);

    float kernel[9];
    kernel[0] = 1.0;kernel[1] = 2.0;kernel[2] = 1.0;
    kernel[3] = 2.0;kernel[4] = 4.0;kernel[5] = 2.0;
    kernel[6] = 1.0;kernel[7] = 2.0;kernel[8] = 1.0;

    vec4 color;//=vec3(0.0);
    for(int i = 0 ; i < 9 ; i ++){
    color += texture2D( vTexture, textureCoordinate+near[i])*kernel[i];
    }

   gl_FragColor = color/14.0;
 }