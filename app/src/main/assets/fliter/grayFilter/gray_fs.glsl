//#extension GL_OES_EGL_image_external : require
precision mediump float;
varying vec2 textureCoordinate;
uniform sampler2D vTexture;

void main()
 {
   gl_FragColor = texture2D( vTexture, textureCoordinate );
   float gray  = (gl_FragColor.r + gl_FragColor.g + gl_FragColor.b)/3.0;
   gl_FragColor = vec4(gray,gray,gray,1.0);
 }